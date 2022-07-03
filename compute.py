import datetime as dt
import os
import re
import sys

MEMBER_LIST = ["말감", "진도", "Yoou", "Marvy", "Muer", "미도리", "Beankong", "안잉", "라임민트", "유감", "Jedi", "OoO", "룰루", "yoon", "dyno0o", "한딱", "Soyou", "서나", "hoodu"]
SOURCE_FILE_EXTENSION = [".java", ".cpp", ".js", ".scala", ".py", ".c"]

problem_count_info = {}
problem_count = {}

class Date:
    def __init__(self, date: str):
        if self.check_date_format(date, '\d\d\d\d-\d\d-\d\d') == False:
            raise ValueError('yyyy-mm-dd 형식을 맞춰주세요')
        self.year = int(date[0:4])
        self.month = int(date[5:7])
        self.day = int(date[8:10])
    
    def __str__(self):
        return self.year + "-" + self.month + "-" + self.day
    
    def check_date_format(self, input: str, format: str):
        if re.compile(format).match(input) == None:
            return False
        return True


def get_formatted_dir_path(day):
    return "./{0}".format(day.strftime("%Y-%m-%d"))


def isSourceFile(path):
    root, extension = os.path.splitext(path)
    if extension in SOURCE_FILE_EXTENSION:
        return True
    return False


def add_member_problem_count(member):
    count = problem_count.get(member) or 0
    problem_count[member] = count + 1


def check_day_member(file_list):
    for file in file_list:
        for member in MEMBER_LIST:
            if member in file:
                add_member_problem_count(member)


def filter_not_included_member(file_list):
    filtered_list = []
    for file in file_list:
        isMember = False
        for member in MEMBER_LIST:
            if member[:2] in file:
                isMember = True
                filtered_list.append(member)
        if not isMember:
            print("없는 멤버입니다 {0}".format(file))
    return filtered_list


def input_date():
    return sys.argv[1]


def get_date_list(start_date: dt.date, n_days: int):
    lst = [start_date]
    for i in range(n_days):
        start_date += dt.timedelta(days=1)
        lst.append(start_date)
    return lst


def get_source_file_list(dir_path):
    file_list = os.listdir(dir_path)
    return list(filter(isSourceFile, file_list))


def is_path_exist(dir_path):
    return os.path.exists(dir_path)


def create_directory(month):
    directory = str(month)+'월'
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)    
    except OSError:
        print('폴더를 만드는 데 실패했습니다.')

def get_memebers_goal(month):
    file = open('README.md','r')
    while True:
        line = file.readline()
        if not line:
            break
        if '## 진행 방식' in line:
            break
        if '# System.out.girls 알고리즘 스터디' in line:
            line = '# ' +str(month)+'월\n'
        if f'## {month}월 스터디원' in line:
            line = '## 참여 인원\n'
        if line.startswith('-'):
            name = get_member_name(line)
        if line.startswith('  -'):
            get_member_goal(line, name)

        with open(f'{month}월/README.md','a') as new_file:
            new_file.writelines(line)
    file.close()


import re
def get_member_name(line):
    l = line.split('**')
    name = l[2].split(' ')[1] +' '+l[1] 
    return name

def get_member_goal(line, name):
    problem_number = re.sub(r'[^0-9]', '', line)
    problem_count_info[name] = problem_number


def count_solved_problems():
    pass



def main():
    to_date = Date(input_date())
    t = dt.date(to_date.year, to_date.month, to_date.day)

    if not is_path_exist(str(to_date.month)+'월/README.md'):
        get_memebers_goal(to_date.month)


    date_list = get_date_list(t, to_date.month)
    for day in date_list:
        dir_path = get_formatted_dir_path(day)
        if is_path_exist(dir_path) == False:
            continue
        source_file_list = get_source_file_list(dir_path)
        member_source_file_list = filter_not_included_member(source_file_list)
        check_day_member(member_source_file_list)
    create_directory(to_date.month)
    print(problem_count)


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main()
    else:
        print('compute.py yyyy-mm-dd')
