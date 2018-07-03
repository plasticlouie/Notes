#
# Anaconda安装特定版本tensorflow，以安装1.7 GPU版为例
# conda install tensorflow-gpu==1.7.0
deerx@deerx-server:~$ conda install tensorflow-gpu==1.7.0
Solving environment: done


==> WARNING: A newer version of conda exists. <==
  current version: 4.4.7
  latest version: 4.5.4

Please update conda by running

    $ conda update -n base conda



## Package Plan ##

  environment location: /home/deerx/husen/anaconda2

  added / updated specs:
    - tensorflow-gpu==1.7.0


The following packages will be downloaded:

    package                    |            build
    ---------------------------|-----------------
    cupti-8.0.61               |                0         1.4 MB  https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    tensorflow-gpu-1.7.0       |                0           3 KB  https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    libgfortran-ng-7.2.0       |       hdf63c60_3         1.2 MB  https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    tensorflow-gpu-base-1.7.0  |   py27h5b7bae4_1       134.3 MB  https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    numpy-1.13.3               |   py27ha266831_3         3.8 MB  https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    ------------------------------------------------------------
                                           Total:       140.8 MB

The following NEW packages will be INSTALLED:

    cupti:               8.0.61-0             https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    libgfortran-ng:      7.2.0-hdf63c60_3     https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    tensorflow-gpu:      1.7.0-0              https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main
    tensorflow-gpu-base: 1.7.0-py27h5b7bae4_1 https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main

The following packages will be UPDATED:

    numpy:               1.13.1-py27_0        defaults                                                --> 1.13.3-py27ha266831_3 https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main

Proceed ([y]/n)? y


Downloading and Extracting Packages
cupti 8.0.61: ################################################################################################################################################### | 100%
tensorflow-gpu 1.7.0: ########################################################################################################################################### | 100%
libgfortran-ng 7.2.0: ########################################################################################################################################### | 100%
tensorflow-gpu-base 1.7.0: ###################################################################################################################################### | 100%
numpy 1.13.3: ################################################################################################################################################### | 100%
Preparing transaction: done
Verifying transaction: done
Executing transaction: done
