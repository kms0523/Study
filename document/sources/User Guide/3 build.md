# 빌드

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