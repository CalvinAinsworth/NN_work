import pandas as pd

frac_train = 0.5 # 0.8

df = pd.read_hdf("input.h5", key="data")
df = df.sample(frac=1).reset_index(drop=True)

nsample = int(len(df)*frac_train)
df_train = df.iloc[:nsample]
df_test = df.iloc[nsample:]

df_train.to_hdf("train.h5", key="data", mode="w")
df_test.to_hdf("test.h5", key="data", mode="w")
