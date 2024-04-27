import requests
from bs4 import BeautifulSoup
import dateparser
import time
from datetime import datetime


r = requests.get(f"https://codeforces.com/profile/darelife")
soup = BeautifulSoup(r.content, "html.parser")

problems = int(soup.find("div", class_="_UserActivityFrame_counterValue").text[:-9])
d = soup.find("div", class_="userbox")

a = d.find("div", class_="info").text.strip().split("\n")[5]

b = soup.find("span", class_="format-humantime").text
dt = dateparser.parse(b)
unixtime = time.mktime(dt.timetuple())
dttime = datetime.fromtimestamp(unixtime)
time_string = (dttime).strftime("%Y-%m-%d %H:%M:%S")
print(time_string)
# unixtime = time.mktime(time.strptime(b, "%B %d, %Y %H:%M:%S"))
print(unixtime)
print(b)

# for i in a:
#     print(i)

# print(a)
if a == "":
    print("NONE")
else:
    print(a)
