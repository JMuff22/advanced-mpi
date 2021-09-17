## HDF5 with python demo

```bash
python hdf5_demo.py
```

Creates `py_test.hdf5`. 

```bash
❯ h5ls py_test.hdf5
Matrix_one               Dataset {5, 7, 9}
```

```bash
❯ h5dump -n 1 py_test.hdf5
HDF5 "py_test.hdf5" {
FILE_CONTENTS {
 group      /
 dataset    /Matrix_one
 attribute  /Matrix_one/mean
 }
}
```