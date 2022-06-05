import datetime as dt
import re
import sys
import os

member = ["말감", "진도", "Yoou", "Marvy", "Muer", "미도리", "Beankong", "안잉", "라임민트", "유감", "Jedi", "OoO", "룰루", "yoon", "dyno0o", "한딱", "Soyou", "서나"]
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

def check_day_member(day: dt.date):
    file_list = os.listdir("./{0}".format(day.strftime("%Y-%m-%d")))
    for file in file_list:
        if file == ".DS_Store":
            continue
        isMember = False
        for m in member:
            if m in file:
                isMember = True
                count = problem_count.get(m) or 0
                problem_count[m] = count + 1

        if not isMember:
            print("없는 멤버입니다 {0}".format(file))

def input_date():
    to_date = sys.argv[1]
    return to_date

def get_date_list(date: dt.date, days: int):
    lst = [date]
    for i in range(days):
        date += dt.timedelta(days=1)
        lst.append(date)
    return lst

def main():
    to_date_str = input_date()
    to_date = Date(to_date_str)

    t = dt.date(to_date.year, to_date.month, to_date.day)
    date_list = get_date_list(t, 6)
    for day in date_list:
        check_day_member(day)
    print(problem_count)


if __name__ == '__main__':
  if len(sys.argv) == 2:
    main()
  else:
    print('compute.py yyyy-mm-dd')