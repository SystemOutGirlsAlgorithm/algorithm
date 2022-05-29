import datetime as dt
import re
import sys
import os

member = ["말감", "진도", "다니", "dukdn", "Yoou", "Marvy", "Muer", "깜콩쥬", "미도리", "YUN", "Beankong", "안잉", "라임민트", "유감", "Jedi", "OoO", "룰루"]
problem_count = {}

def get_time_range_list(month, to_day, from_day, file_list):
    # 조금 더 현명하게 날짜를 계산하는 방법이 필요
    pattern = re.compile('2022-{0}-2[{1}-{2}]'.format(month, to_day, from_day))
    return list(filter(lambda file: pattern.match(file) , file_list))

def check_day_member(day):
    file_list = os.listdir("./{0}".format(day))
    for file in file_list:
        isMember = False
        for m in member:
            if m in file:
                isMember = True
                count = problem_count.get(m) or 0
                problem_count[m] = count + 1

        if not isMember:
            print("없는 멤버입니다 {0}".format(file))

def main():
    month, to_day, from_day = sys.argv[1], sys.argv[2], sys.argv[3]
    print(month, to_day, from_day)

    file_list = os.listdir("./")
    time_range_list = get_time_range_list(month, to_day, from_day, file_list)
    for day in time_range_list:
        check_day_member(day)
    print(problem_count)


if __name__ == '__main__':
  if len(sys.argv) == 4:
    main()