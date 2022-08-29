
## Requirements
- CUDA 11.3
- cuDNN 8.4.1
- Libtorch 1.12.0 (built with CUDA 11.3) https://download.pytorch.org/libtorch/cu113/libtorch-win-shared-with-deps-1.12.1%2Bcu113.zip
- TensorRT 8.4.1.5 https://developer.nvidia.com/compute/machine-learning/tensorrt/secure/8.4.3/zip/TensorRT-8.4.3.1.Windows10.x86_64.cuda-11.6.cudnn8.4.zip
- cmake 3.23.1^

## Scripts
- 아래 스크립트는 ps1 에서 실행할 수 있습니다.
- 기존 CUDA 가 설치되어있어서 `CUDA_PATH_V1x_x` 가 있다면, 그 환경변수 값을 초기화해주세요
  - 환경 변수 확인하는 방법 : ``gci env:*``
- 만약 cmake 중 실패했다면 `release` 디렉토리를 삭제하고 다시 cmake 를 실행해주세요.

``` 
$env:CUDA_PATH_V1x_x=""
```

``` sh
## torch-tensorRT cmake 실행하기
$env:CUDA_PATH=</path/to/cuda>
$env:PATH=</path/to/cuda/bin>
$env:CUDA_PATH_V11_3=</path/to/cuda>
cmake -S. -Brelease -DTorch_DIR="D:\DevEnv\Workspace\latest\libtorch-win-shared-with-deps-1.12.1+cu113\libtorch\share\cmake\Torch" -DTensorRT_ROOT="D:\DevEnv\Workspace\latest\TensorRT-8.4.3.1.Windows10.x86_64.cuda-11.6.cudnn8.4\TensorRT-8.4.3.1" -DCMAKE_BUILD_TYPE="Release" -DCMAKE_PREFIX_PATH="D:\DevEnv\Workspace\latest\TensorRT-8.4.3.1.Windows10.x86_64.cuda-11.6.cudnn8.4\TensorRT-8.4.3.1;D:\DevEnv\Workspace\latest\libtorch-win-shared-with-deps-1.12.1+cu113\libtorch"
```

``` sh
## torch-tensorRT 빌드하기
cmake --build release
```
