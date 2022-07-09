import datetime as dt
import os
import re
import sys

MEMBER_LIST = ["🎱 말감", "🧶 진도", "🐧 Yoou", "🕶️ Marvy", "☁ Muer", "👻 미도리", "🌊 Beankong", "❄️ 안잉", "S2 라임민트", "🍒 유감", "🖖 Jedi", "🐯 OoO", "🎈 룰루", "⛄ yoon", "🦕 dyno0o", "🐋 한딱", "🌈 Soyou", "🔥 서나", "🐱 hoodu"]
SOURCE_FILE_EXTENSION = [".java", ".cpp", ".js", ".scala", ".py", ".c"]

members_goal = {}
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
            member_name = member.split(' ')[1]
            if member_name in file:
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


def create_directory(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)    
    except OSError:
        print('폴더를 만드는 데 실패했습니다.')


def get_or_write_memebers_goal(month_name):
    file = open('README.md','r')

    if not is_path_exist(month_name+'/README.md'):
        while True:
            line = file.readline()

            if not line:
                break
            if '## 진행 방식' in line:
                break
            elif '# System.out.girls 알고리즘 스터디' in line:
                line = '# ' +month_name+'\n'
            elif f'## {month_name} 스터디원' in line:
                line = '## 참여 인원\n'

            if line.startswith('-'):
                name = get_member_name(line)
            elif line.startswith('  -'):
                save_member_goal(line, name)

            with open(f'{month_name}/README.md','a') as new_file:
                new_file.writelines(line)

    else:
        while True:
            line = file.readline()
            if not line:
                break
            if '## 진행 방식' in line:
                break
            if line.startswith('-'):
                name = get_member_name(line)
            elif line.startswith('  -'):
                save_member_goal(line, name)
            
    file.close()


def get_member_name(line):
    l = line.split('**')
    name = l[2].split(' ')[1] +' '+l[1] 
    return name


def get_member_goal(line):
    return re.sub(r'[^0-9]', '', line)


def save_member_goal(line, name):
    members_goal[name] = get_member_goal(line)


def set_week_number(month_name, day):
    week = day // 7 + 1
    title = f'### {month_name} {week}주\n\n'

    with open(f'{month_name}/README.md','a') as new_file:
        if week == 1:
            new_file.writelines('## 목표 달성\n\n')
        new_file.writelines(title)  

    

def get_results():
    result = ''
    for key in members_goal:
        
        problem_num = problem_count.get(key) or '0'

        result += key + '(' + str(members_goal[key]) + ') ' + str(problem_num)
        if int(problem_num) >= int(members_goal[key]):
            result += ' 🏅'
        result += '\n'
    return result


def write_results(month_name, day):
    set_week_number(month_name, day)
    result = get_results()

    with open(f'{month_name}/README.md','a') as new_file:
        new_file.writelines(result) 
        new_file.writelines('\n') 



def main():
    start_date_of_week = Date(input_date())
    t = dt.date(start_date_of_week.year, start_date_of_week.month, start_date_of_week.day)
    month_name = str(start_date_of_week.month)+'월'

    get_or_write_memebers_goal(month_name)

    date_list = get_date_list(t, start_date_of_week.month)
    for day in date_list:
        dir_path = get_formatted_dir_path(day)
        if is_path_exist(dir_path) == False:
            continue
        source_file_list = get_source_file_list(dir_path)
        member_source_file_list = filter_not_included_member(source_file_list)
        
        check_day_member(member_source_file_list)

    create_directory(month_name)
    write_results(month_name, start_date_of_week.day)

if __name__ == '__main__':
    if len(sys.argv) == 2:
        main()
    else:
        print('compute.py yyyy-mm-dd')