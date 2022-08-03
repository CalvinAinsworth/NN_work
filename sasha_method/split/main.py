import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages


os.environ["CUDA_VISIBLE_DEVICES"] = "0" # -1 if no GPU
os.environ["CUDA_DEVICE_ORDER"] = "PCI_BUS_ID"

# read data from hdf5
df = pd.read_hdf('train.h5', key='data')
print(df)

import json

with open("input_Variables.json") as vardict:
    input_vars = json.load(vardict)[:]
print(input_vars)

from sklearn.preprocessing import StandardScaler
scaler = StandardScaler()

x_train = scaler.fit_transform(df[input_vars].values)
y_train = df['out'].values

# reserve a fraction of data for validation
frac_train = 0.8
ntrain = int(len(x_train)*frac_train)
x_val = x_train[ntrain:]
y_val = y_train[ntrain:]
x_train = x_train[:ntrain]
y_train = y_train[:ntrain]

import pickle
with open('scaler.pkl','wb') as pfile:
    pickle.dump(scaler, pfile)

from tensorflow import keras
from tensorflow.keras import layers

model = keras.Sequential([
  layers.Input(shape=(len(input_vars),)),
  layers.Dense(60, kernel_initializer="lecun_normal", activation="relu"),
  layers.Dense(30, kernel_initializer="lecun_normal", activation="relu"),
  layers.Dense(15, kernel_initializer="lecun_normal", activation="relu"),
  layers.Dense(2, activation="sigmoid")
])

model.summary()

model.compile(optimizer="Adagrad", loss=keras.losses.SparseCategoricalCrossentropy(), metrics=["acc"])

history = model.fit(x_train, y_train, epochs=40, batch_size=100, verbose=2, validation_data=(x_val, y_val))
print(history.history)

model.save("model.h5", save_format="h5")

train = history.history['acc']
test = history.history['val_acc']
train_loss = history.history['loss']
test_loss = history.history['val_loss']
epoch = np.arange(1, len(train)+1)



fig1 = plt.figure("Epoch")
plt.plot(epoch, train, 'b', label = 'training')
plt.plot(epoch, test, 'r', label = 'testing')
plt.xlabel('epochs')
plt.ylabel('accuracy')
plt.legend()
plt.grid()



fig2 = plt.figure("Loss")
plt.plot(epoch, train_loss, 'b', label = 'training')
plt.plot(epoch, test_loss, 'r', label = 'testing')
plt.xlabel('epochs')
plt.ylabel('loss')
plt.legend()
plt.grid()


def save_multi(filename):
    pp = PdfPages(filename)
    fig_nums = plt.get_fignums()
    figs = [plt.figure(n) for n in fig_nums]
    for fig in figs:
        fig.savefig(pp, format='pdf')
        
    pp.close() 

filename = "epoch.pdf" 
save_multi(filename)  
