# 🎁 Wishlist Manager
> **조건 해금형 위시리스트 관리 프로그램**

---

## 📌 주요 기능

* **✨ 위시 관리**: 위시(물건, 활동 등) 추가, 수정 및 삭제
* **🎯 다양한 달성 조건 설정**:
  * **저축액**: 목표 금액 설정 및 현재 저축액 관리
  * **날짜**: 생일 등 기준 날짜 설정
  * **체크리스트**: 세부 수행 과제 체크리스트 관리
* **🔓 자동 해금 시스템**: 설정한 달성 조건을 모두 만족하면 위시가 자동으로 해금
* **📜 히스토리 관리**: 해금된 위시를 완료 처리한 뒤, 히스토리 목록으로 이동하여 열람 가능
* **💾 데이터 관리**: JSON 포맷을 기반으로 데이터를 저장 및 로드

---

<img width="1048" height="742" alt="image" src="https://github.com/user-attachments/assets/3bd7de00-0990-444e-bf87-a0d62b89f38e" />
<img width="1054" height="744" alt="image" src="https://github.com/user-attachments/assets/ea2641e9-d1d8-4da4-895e-96e9cc700a91" />
<img width="1042" height="740" alt="image" src="https://github.com/user-attachments/assets/b9428081-c584-4872-b495-f186a719f4fe" />

---
## 🛠 사용 기술 (Tech Stack)

C++
Qt Widgets
CMake
nlohmann/json

---

## 🏗 주요 클래스 (Architecture)

* **`Wishlist`**: 전체 위시 목록 및 저축액 관리
* **`Wish`**: 개별 위시의 정보 관리
* **`Checklist`**: 위시 내부의 체크리스트 항목 관리
* **`MainWindow`**: 메인 UI
* **`WishDialog`**: 위시 추가/수정
* **`WishHistory`**: 완료된 위시 열람

---

## 🎯 프로젝트 목적

C++ 기반 GUI 개발 및 라이브러리 활용 능력 향상을 위한 프로젝트입니다😊

- **Qt Widgets**: C++ GUI 프레임워크 활용 및 기본 화면 구성 학습
- **객체지향 프로그래밍**: 클래스 분리를 통한 데이터 관리 및 객체 간 상호작용 실습
- **nlohmann/json**: C++ 환경에서의 JSON 데이터 입출력(저장 및 불러오기) 구현 연습
---

## 🚀 시작하기 (Build & Run)

### 빌드 및 실행 방법

```bash
# 1. 빌드 디렉토리 생성 및 이동
mkdir build && cd build

# 2. CMake 설정 및 빌드
cmake ..
cmake --build .

# 3. 프로그램 실행
./WishlistManager
