# Embedded Cpp Project with CppUTest(Unittest)

## 사전 준비사항

### 1. tools setup
- git
- docker
- vscode
  - Dev Containers 확장

### 2. docker저장소 login in host pc
```sh
docker login https://git.etc-lab.kr
id: <your_id>
pass: <your_password>
```

### 3. 소스코드 다운로드 및 vscode 에서 열기
```sh
git clone https://git.etc-lab.kr/ik1022/test_01.git test_01
cd test_01
code .
```

### 4. vscode 에서 컨테이너로 열기


## Build in DevContainer

### 1. _build.sh
```sh
rm -Rf .build
cmake -S. -B.build -GNinja
cmake --build .build --clean-first

mkdir .bin
arm-none-eabi-objcopy -Oihex .build/mcu.elf .bin/mcu.hex

arm-none-eabi-size --format=berkeley .build/mcu.elf
```

### 2. _unittest.sh
```sh
rm -Rf .build_test
cmake -S. -B.build_test -GNinja -DBUILD_FOR_UNIT_TESTS=ON
cmake --build .build_test --clean-first
ctest  --test-dir .build_test/
```

### 3. _clean.sh
```sh
rm -Rf .build
rm -Rf .build_test
```



## Flash,Erase,Debug with pyocd
### 1. host pc 에서 pyocd 서버 실행
```sh
pyocd server --allow-remote
```

### 2. in container 에서 원격으로 pyocd 접속
_flash.sh
```sh
pyocd flash -uremote:host.docker.internal:5555 .bin/mcu.hex
```
_erase.sh
```sh
pyocd erase -uremote:host.docker.internal:5555 --mass
```

## 단축키
- 테스트 빌드 F7
- 테스트실행 ctrl+; a

## 주의사항
- 쉘스크립트 파일의 줄바꿈은 LF 를 사용하도록 한다.


## 앞으로 할일
- [ ] vscode 에서 pyocd 를 통한 디버깅 설정
- [ ] vscode 유닛테스트 확장 설정
- [ ] gitea act 를 통한 CI/CD 설정
- [ ] cpp 컴파일 테스트
- [x] 쉘스크립트 실행 안되는 문제 해결
