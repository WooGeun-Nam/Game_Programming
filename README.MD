# GameCoding : Windows API GameClient

---

속성 -> c/c++ -> 미리 컴파일된 헤더
pch.h (pre compile header)

Defines.h 매크로 관리
ex) singleton 매크로

Types.h 자주 사용하는 변수타입을 편한 형태로 변경

FPS 프레임 단위
시간 차 (반복 간 Tick을 제한함으로써 프레임 제한) : frame rate

c++ 20 에 추가된 기능 format
```
wstring str = format(L"FPS({0}), DT({1}) ms", fps, static_cast<int32>(deltaTime * 1000));
::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
```

::GetAsyncKeyState() -> 여러번 호출하게 되면 속도가 느려진다
전체 키보드의 상태를 통으로 긁어옴, 매 프레임 당