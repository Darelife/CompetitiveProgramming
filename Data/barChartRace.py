import json
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import bar_chart_race as bcr
from datetime import datetime

with open("algoX.json", "r") as f:
    initialData = json.load(f)

data = {}
for user in initialData:
    if initialData[user]["algo"] == 0:
        continue
    if user not in [
        "darelife",
        "harshb",
        "acsde",
        "garam_icecream",
        "Centelle",
        "Aashman",
    ]:
        continue
    data[user] = initialData[user]["ratingHistory"]

# Data:
# -> {user:[{rating, time(unix), rank},...], ...}

"""
A bar chart race video with the top 10 users with the highest rating at any given time.
"""

# Dataframe
dfs = []  # list to hold dataframes
for user in data:
    ratings = []
    times = []
    for x in data[user]:
        # if x["time"] < 1640975401:
        if x["time"] < 1672511401:
            continue
        ratings.append(x["rating"])
        # times.append(x["time"])
        times.append(datetime.fromtimestamp(int(x["time"])))
    temp_df = pd.DataFrame({user: ratings, "time": times})
    temp_df = temp_df.set_index("time")
    dfs.append(temp_df)

# Concatenate all the dataframes
df = pd.concat(dfs, axis=1)

df = df.sort_index()

# Top 10 users with the highest rating at any given time
top10 = df.apply(lambda x: x.sort_values(ascending=False).head(10).index, axis=1)

# Convert the index to a DatetimeIndex
df.index = pd.to_datetime(df.index)

# Now you can resample
df_daily = df.resample("D").mean()

# Interpolate missing values
df_interpolated = df_daily.interpolate()

# Create the bar chart race
bcr.bar_chart_race(
    df=df_interpolated,
    filename="bar_chart_race.mp4",
    title="Top 10 Users with Highest Rating",
    n_bars=10,
    # period_length=100,
    period_length=300,
    # period_length=500,
)
