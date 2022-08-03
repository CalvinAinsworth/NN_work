import uproot
import pandas as pd
import json

with open("input_Variables.json") as vardict:
    keys = json.load(vardict)[:]

with open("spectator_Variables.json") as vardict:
    keys += json.load(vardict)[:]

print(keys)

root_file = uproot.open('/afs/cern.ch/work/c/cainswor/public/NN_test/ttbarJetML/SamplePrep/input/tt_jets_NN_input.root')

tree_sig = root_file['NN_signal']
nev_sig = tree_sig.num_entries
print("signal events:",nev_sig)
df_sig = tree_sig.arrays(keys,library='pd')
out_sig = [1.]*nev_sig
df_sig['out'] = out_sig
print(df_sig)

tree_bkg = root_file['NN_background']
nev_bkg = tree_bkg.num_entries
print("background events:",nev_bkg)
df_bkg = tree_bkg.arrays(keys,library='pd')
df_bkg.index += nev_sig
out_bkg = [0.]*nev_bkg
df_bkg['out'] = out_bkg
print(df_bkg)

data = [df_sig, df_bkg]
df = pd.concat(data)

df.to_hdf('input.h5',key='data',mode='w')
