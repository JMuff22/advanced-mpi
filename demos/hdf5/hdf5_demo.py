import h5py
import numpy as np 

m1_shape=(5,7,9)
M1=np.random.random(m1_shape)

hdf5_fn='py_test.hdf5'

with h5py.File(hdf5_fn, 'w') as f:
	ds_n='Matrix_one'
	dset=f.create_dataset(ds_n, data=M1, compression='gzip')
	dset.attrs['mean']=np.mean(np.mean(M1))

