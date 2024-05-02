from matplotlib import pyplot as plt
import json
from datetime import datetime
import seaborn as sns

with open("algoX.json", "r") as f:
    initialData = json.load(f)

data = {}
for user in initialData:
    if initialData[user]["algo"] == 0:
        continue
    # if user in ["darelife", "harshb", "acsde", "garam_icecream", "Centelle", "Aashman"]:
    data[user] = initialData[user]["ratingHistory"]

"""
Data:
-> {user:[{rating, time(unix), rank},...], ...}

We need to plot a multi-line graph (rating vs time) with the following data:
"""


def plot_graph(data):
    # sns.set_theme()
    sns.set_theme(style="darkgrid")
    for user in data:
        ratings = []
        times = []
        for x in data[user]:
            # 1640975401
            # 1672511401
            if x["time"] < 1640975401:
                continue
            ratings.append(x["rating"])
            times.append(datetime.fromtimestamp(int(x["time"])))
        # ratings = [x["rating"] for x in data[user]]
        # times = [datetime.fromtimestamp(int(x["time"])) for x in data[user]]
        plt.plot(times, ratings, label=user)
    plt.xlabel("Time")
    plt.ylabel("Rating")
    plt.legend()
    plt.savefig("ratingVsTime.png")
    plt.show()


plot_graph(data)
