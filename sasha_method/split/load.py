import pandas as pd
import numpy as np
import os

os.environ["CUDA_VISIBLE_DEVICES"] = "0" # -1 if no GPU
os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID"

# read data from hdf5
df = pd.read_hdf('test.h5', key='data')
df_inputs = df.drop(columns=['out'])

import json

with open("spectator_Variables.json") as vardict:
    spec_vars = json.load(vardict)[:]
df_inputs.drop(spec_vars,axis='columns',inplace=True)

print(df_inputs)

from sklearn.preprocessing import StandardScaler

import pickle
with open('scaler.pkl','rb') as pfile:
    scaler = pickle.load(pfile)

inputs = scaler.transform(df_inputs.to_numpy())
print(inputs)

from tensorflow import keras
from tensorflow.keras import layers
model = keras.models.load_model("model.h5")

# pred = model.predict_classes(inputs) # deprecated
pred = model.predict(inputs, batch_size=8196)
print(pred)

# add to inputs and save
df[['res1','res2']] = pred
print(df)

df.to_hdf('result.h5',key='data',mode='w')
