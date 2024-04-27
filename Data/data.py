import requests
import json
import hashlib
import time
from bs4 import BeautifulSoup
from dotenv import load_dotenv
import os
import dateparser
from datetime import datetime

load_dotenv()
KEY = os.getenv("KEY")
SECRET = os.getenv("SECRET")
USER = os.getenv("USER")

"""
If your key is xxx, secret is yyy, chosen rand is 123456 and you want to access method contest.hacks for contest 566, you should compose request like this: https://codeforces.com/api/contest.hacks?contestId=566&apiKey=xxx&time=1714044447&apiSig=123456<hash>, where <hash> is sha512Hex(123456/contest.hacks?apiKey=xxx&contestId=566&time=1714044447#yyy)
"""

methodName = "user.friends"


def getData(methodName, handle, handles):
    URL = "https://codeforces.com/api/{methodName}"
    currentTime = int(time.time())
    rand = 123456

    if methodName == "user.rating":
        hashString = f"{rand}/{methodName}?apiKey={KEY}&handle={handle}&time={currentTime}#{SECRET}"
        apiSig = hashlib.sha512(hashString.encode()).hexdigest()

        # Request
        response = requests.get(
            URL.format(methodName=methodName),
            params={
                "apiKey": KEY,
                "time": currentTime,
                "apiSig": f"{rand}{apiSig}",
                "handle": handle,
            },
        )

        # Response
        data = json.loads(response.text)

        with open("algoX.json", "w") as file:
            json.dump(data, file, indent=2)

        return data

    elif methodName == "user.info":

        hashString = f"{rand}/{methodName}?apiKey={KEY}&handles={handles}&time={currentTime}#{SECRET}"
        apiSig = hashlib.sha512(hashString.encode()).hexdigest()

        # Request
        response = requests.get(
            URL.format(methodName=methodName),
            params={
                "apiKey": KEY,
                "time": currentTime,
                "apiSig": f"{rand}{apiSig}",
                "handles": handles,
            },
        )

        # Response
        data = json.loads(response.text)

        with open("algoX.json", "w") as f:
            json.dump(data, f, indent=2)

        return data

    elif methodName == "user.friends":

        hashString = f"{rand}/{methodName}?apiKey={KEY}&handles={handles}&time={currentTime}#{SECRET}"
        apiSig = hashlib.sha512(hashString.encode()).hexdigest()

        # Request
        response = requests.get(
            URL.format(methodName=methodName),
            params={
                "apiKey": KEY,
                "time": currentTime,
                "apiSig": f"{rand}{apiSig}",
                "handles": handles,
            },
        )

        # Response
        data = json.loads(response.text)

        with open("algoX.json", "w") as f:
            json.dump(data, f, indent=2)

        return data

    elif methodName == "problemset.problems":
        hashString = f"{rand}/{methodName}?apiKey={KEY}&time={currentTime}#{SECRET}"
        apiSig = hashlib.sha512(hashString.encode()).hexdigest()

        # Request
        response = requests.get(
            URL.format(methodName=methodName),
            params={"apiKey": KEY, "time": currentTime, "apiSig": f"{rand}{apiSig}"},
        )

        # Response
        data = json.loads(response.text)

        with open("algoX.json", "w") as f:
            json.dump(data, f, indent=2)

        return data


with open("algoXmembers.json", "r") as f:
    algoXmembers = json.load(f)

friends = getData("user.friends", USER, USER)["result"]

data = {}
dd = getData("user.info", USER, ";".join(friends))["result"]
for i in range(len(friends)):
    data[friends[i]] = {}
    try:
        rr = getData("user.rating", friends[i], friends[i])["result"]
        time.sleep(2)
        data[friends[i]]["ratingHistory"] = []
        for j in rr:
            data[friends[i]]["ratingHistory"].append(
                {"rating": j["newRating"], "rank": j["rank"]}
            )
    except:
        data[friends[i]]["ratingHistory"] = []
    try:
        data[friends[i]]["rating"] = dd[i]["rating"]
        data[friends[i]]["maxRating"] = dd[i]["maxRating"]
    except:
        data[friends[i]]["rating"] = 0
        data[friends[i]]["maxRating"] = 0

    try:
        r = requests.get(f"https://codeforces.com/profile/{friends[i]}")
        soup = BeautifulSoup(r.content, "html.parser")

        try:
            data[friends[i]]["problems"] = int(
                soup.find("div", class_="_UserActivityFrame_counterValue").text[:-9]
            )
        except:
            data[friends[i]]["problems"] = 0

        try:
            d = soup.find("div", class_="userbox")

            a = d.find("div", class_="info").text.strip().split("\n")[5]

            if a == "":
                data[friends[i]]["name"] = "NONE"
                data[friends[i]]["origin"] = "NONE"
            else:
                data[friends[i]]["name"] = a.split(",")[0]
                if (len(a.split(","))) == 1:
                    data[friends[i]]["origin"] = a.split(",")[1]
                elif (len(a.split(","))) > 1:
                    data[friends[i]]["origin"] = ", ".join(a.split(",")[1:])
                else:
                    data[friends[i]]["origin"] = "NONE"
        except:
            data[friends[i]]["name"] = "NONE"
            data[friends[i]]["origin"] = "NONE"

        try:
            b = soup.find("span", class_="format-humantime").text
            dt = dateparser.parse(b)
            unixtime = time.mktime(dt.timetuple())
            dttime = datetime.fromtimestamp(unixtime)
            time_string = (dttime).strftime("%Y-%m-%d %H:%M:%S")

            data[friends[i]]["registered"] = time_string
        except:
            data[friends[i]]["registered"] = "NONE"

    except:
        data[friends[i]]["problems"] = 0
        data[friends[i]]["name"] = "NONE"
        data[friends[i]]["origin"] = "NONE"
        data[friends[i]]["registered"] = "NONE"

    print(
        f"{friends[i]} -> maxRating : {data[friends[i]]['maxRating']}, rating : {data[friends[i]]['rating']}, problems : {data[friends[i]]['problems']}, name : {data[friends[i]]['name']}, origin : {data[friends[i]]['origin']}, registered : {data[friends[i]]['registered']}, rank : {data[friends[i]]['ratingHistory'][-1]['rank']}"
    )
    time.sleep(2)

dd = getData("user.info", USER, USER)["result"]
data[USER] = {}
try:
    rr = getData("user.rating", USER, USER)["result"]
    time.sleep(2)
    data[USER]["ratingHistory"] = []
    for j in rr:
        data[USER]["ratingHistory"].append(
            {"rating": j["newRating"], "rank": j["rank"]}
        )
except:
    data[USER]["ratingHistory"] = []
try:
    data[USER]["rating"] = dd[0]["rating"]
    data[USER]["maxRating"] = dd[0]["maxRating"]
except:
    data[USER]["rating"] = 0
    data[USER]["maxRating"] = 0

try:
    r = requests.get(f"https://codeforces.com/profile/{USER}")
    soup = BeautifulSoup(r.content, "html.parser")

    data[USER]["problems"] = int(
        soup.find("div", class_="_UserActivityFrame_counterValue").text[:-9]
    )

    d = soup.find("div", class_="userbox")

    a = d.find("div", class_="info").text.strip().split("\n")[5]

    if a == "":
        data[USER]["name"] = "NONE"
        data[USER]["origin"] = "NONE"
    else:
        data[USER]["name"] = a.split(",")[0]
        if (len(a.split(","))) == 1:
            data[USER]["origin"] = a.split(",")[1]
        elif (len(a.split(","))) > 1:
            data[USER]["origin"] = ", ".join(a.split(",")[1:])
        else:
            data[USER]["origin"] = "NONE"

    try:
        b = soup.find("span", class_="format-humantime").text
        dt = dateparser.parse(b)
        unixtime = time.mktime(dt.timetuple())
        dttime = datetime.fromtimestamp(unixtime)
        time_string = (dttime).strftime("%Y-%m-%d %H:%M:%S")

        data[USER]["registered"] = time_string
    except:
        data[USER]["registered"] = "NONE"

except:
    data[USER]["problems"] = 0
    data[USER]["name"] = "NONE"
    data[USER]["origin"] = "NONE"
    data[USER]["registered"] = "NONE"

print(
    f"{USER} -> maxRating : {data[USER]['maxRating']}, rating : {data[USER]['rating']}, problems : {data[USER]['problems']}, name : {data[USER]['name']}, origin : {data[USER]['origin']}, registered : {data[USER]['registered']}, rank : {data[USER]['ratingHistory'][-1]['rank']}"
)

with open("algoX.json", "w") as f:
    json.dump(data, f, indent=2)


# data = getData("user.info", USER, USER)["result"]

# import json

# with open("algoX.json", "r") as f:
#     data = json.load(f)

# # sort by rating

data = dict(sorted(data.items(), key=lambda x: x[1]["rating"], reverse=True))

algoRank = 0
for i in data:
    data[i]["rank"] = list(data.keys()).index(i) + 1
    if i in algoXmembers or i == USER:
        data[i]["algo"] = algoRank + 1
        algoRank += 1
    else:
        data[i]["algo"] = 0

zero = 0
n0to300 = 0
n300to500 = 0
n500to800 = 0
n800to900 = 0
n900to1000 = 0
n1000to1100 = 0
n1100to1200 = 0
n1200to1300 = 0
n1300to1400 = 0
n1400to1500 = 0
n1500to1600 = 0
n1600to1700 = 0
n1700to1800 = 0
n1800to1900 = 0
n1900to2000 = 0
n2000to2100 = 0
n2100to2200 = 0
n2200to2300 = 0
n2300plus = 0

for i in data:
    rating = data[i]["rating"]
    if rating == 0:
        zero += 1
    elif rating <= 300:
        n0to300 += 1
    elif rating <= 500:
        n300to500 += 1
    elif rating <= 800:
        n500to800 += 1
    elif rating <= 900:
        n800to900 += 1
    elif rating <= 1000:
        n900to1000 += 1
    elif rating <= 1100:
        n1000to1100 += 1
    elif rating <= 1200:
        n1100to1200 += 1
    elif rating <= 1300:
        n1200to1300 += 1
    elif rating <= 1400:
        n1300to1400 += 1
    elif rating <= 1500:
        n1400to1500 += 1
    elif rating <= 1600:
        n1500to1600 += 1
    elif rating <= 1700:
        n1600to1700 += 1
    elif rating <= 1800:
        n1700to1800 += 1
    elif rating <= 1900:
        n1800to1900 += 1
    elif rating <= 2000:
        n1900to2000 += 1
    elif rating <= 2100:
        n2000to2100 += 1
    elif rating <= 2200:
        n2100to2200 += 1
    elif rating <= 2300:
        n2200to2300 += 1
    else:
        n2300plus += 1

print("Unrated : ", zero)
print("0-300 : ", n0to300)
print("300-500 : ", n300to500)
print("500-800 : ", n500to800)
print("800-900 : ", n800to900)
print("900-1000 : ", n900to1000)
print("1000-1100 : ", n1000to1100)
print("1100-1200 : ", n1100to1200)
print("1200-1300 : ", n1200to1300)
print("1300-1400 : ", n1300to1400)
print("1400-1500 : ", n1400to1500)
print("1500-1600 : ", n1500to1600)
print("1600-1700 : ", n1600to1700)
print("1700-1800 : ", n1700to1800)
print("1800-1900 : ", n1800to1900)
print("1900-2000 : ", n1900to2000)
print("2000-2100 : ", n2000to2100)
print("2100-2200 : ", n2100to2200)
print("2200-2300 : ", n2200to2300)
print("2300+ : ", n2300plus)

"""
Unrated :  8
0-300 :  0
300-500 :  8
500-800 :  7
800-900 :  9
900-1000 :  10
1000-1100 :  3
1100-1200 :  6
1200-1300 :  5
1300-1400 :  0
1400-1500 :  11
1500-1600 :  4
1600-1700 :  5
1700-1800 :  1
1800-1900 :  2
1900-2000 :  0
2000-2100 :  1
2100-2200 :  0
2200-2300 :  0
2300+ :  2
"""

with open("algoX.json", "w") as f:
    json.dump(data, f, indent=2)


# import json

# with open("algoX.json", "r") as f:
#     data = json.load(f)

# algoXmembers = []

# for i in data:
#     if "algo" in data[i]:
#         algoXmembers.append(i)

# print(algoXmembers)

# with open("algoXmembers.json", "w") as f:
#     json.dump(algoXmembers, f, indent=2)


# FIXING THE INDENTATION : Custom Indentation for the JSON data


class NoIndentList(list):
    pass


# # Function to serialize the dictionary with custom indentation
# def serialize(data, level=0):
#     if isinstance(data, dict):
#         indent = "  " * level
#         items = []
#         for key, value in data.items():
#             if isinstance(value, list):
#                 items.append(
#                     f'{indent}"{key}": {json.dumps(value, separators=(",", ":"))}'
#                 )
#             elif isinstance(value, dict):
#                 items.append(f'{indent}"{key}": {serialize(value, level + 1)}')
#             else:
#                 items.append(f'{indent}"{key}": {json.dumps(value)}')
#         # Join the items with a comma and a newline, but don't add a comma after the last item
#         return "{{\n{}\n{}}}".format(",\n".join(items), indent)
#     elif isinstance(data, NoIndentList):
#         return json.dumps(data, separators=(",", ":"))
#     else:
#         return json.dumps(data)


def serialize(data, level=0):
    indent = "  " * level
    items = []
    for key, value in data.items():
        if isinstance(value, list):
            items.append(
                f'{indent}  "{key}": {json.dumps(value, separators=(",", ":"))}'
            )
        elif isinstance(value, dict):
            items.append(f'{indent}  "{key}": {serialize(value, level + 1)}')
        else:
            items.append(f'{indent}  "{key}": {json.dumps(value)}')
    # Join the items with a comma and a newline, but don't add a comma after the last item
    return "{{\n{}\n{}}}".format(",\n".join(items), indent)


# Load the JSON data
with open("./algoX.json", "r") as f:
    data = json.load(f)

# Wrap the data in NoIndent objects to prevent indentation for 'ratingHistory'
for key, value in data.items():
    value["ratingHistory"] = NoIndentList(value.get("ratingHistory", []))

# Serialize the data
serialized_data = serialize(data)

# Write the serialized data to the file
with open("./algoX.json", "w") as f:
    f.write(serialized_data)
