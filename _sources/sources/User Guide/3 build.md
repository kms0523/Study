# 빌드

## 빌드 환경 설정
* 손쉬운 가상 환경을 위해 Anaconda를 사용합니다.
* Anaconda prompt에서 Jupyterbook 가상환경을 만듭니다
```
conda create -n jupyterbook python=3.9
```
* 가상환경에 들어갑니다
```
conda activate jupyterbook
```
* conda를 업데이트 해줍니다.
```
conda update --all
```
* Jupyterbook을 설치합니다.
  * conda에서 설치 - 가장 간단한 방법인데 왜 인지 안된다
```
conda install -c conda-forge jupyter-book
```  
  * mamba를 사용하여 설치 - 현재 되는 방법
```
conda install -c conda-forge mamba
mamba install -c conda-forge jupyter-book
```

> Reference  
> [jupyterbook](https://jupyterbook.org/en/stable/start/overview.html)

## 빌드 환경

Python 3.9
Jupyter Book 0.13.1

## 빌드 방법
* anaconda prompt 실행
* jupyter 가상환경을 실행
```
conda activate jupyterbook
```
* make.py가 있는 폴더로 이동
```
cd (path)
```
* 명령어 실행

```bash
# Build
python -m make build

# Clean
python -m make Clean

# Rebuild
python -m make Rebuild
```
* `_build/build/index.html` 파일을 열어서 확인