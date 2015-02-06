SET(NAME possamp)

add_executable(
  ${PROJECT_NAME}
  main.cpp

  Util.h
  Util.cpp  

  ObjectManager.h
  ObjectManager.cpp

  MainWindow.h
  MainWindow.cpp

  ImageWidget.h
  ImageWidget.cpp
  )

qt5_use_modules(
  ${PROJECT_NAME}  
  Core
  Gui
  Widgets
  )