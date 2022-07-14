import datetime as dt
import os
import re
import sys

MEMBER_LIST = ["말감", "진도", "Yoou", "Marvy",  "안잉", "라임민트", "dyno0o", "서나", "김연못", "hyun", "집", "가지덮밥", "차미", "파도", "yeonjiyeon", "봉봉", "ramu", "두괴풋"]
SOURCE_FILE_EXTENSION = [".java", ".cpp", ".js", ".scala", ".py", ".c", ".ipynb"]

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
            if member in file:
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


def main():
    to_date = Date(input_date())
    t = dt.date(to_date.year, to_date.month, to_date.day)
    date_list = get_date_list(t, 6)
    for day in date_list:
        dir_path = get_formatted_dir_path(day)
        if is_path_exist(dir_path) == False:
            continue
        source_file_list = get_source_file_list(dir_path)
        member_source_file_list = filter_not_included_member(source_file_list)
        check_day_member(member_source_file_list)
    print(problem_count)


if __name__ == '__main__':
    if len(sys.argv) == 2:
        main()
    else:
        print('compute.py yyyy-mm-dd')
