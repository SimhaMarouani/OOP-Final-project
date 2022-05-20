target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources (${CMAKE_PROJECT_NAME} PRIVATE 
                                              "Controller.h"
                                              "Board.h"
                                              "Window.h"
                                              "DataDisplay.h"
                                              "Animation.h"
                                              "Audio.h"
                                              "Button.h"
                                              "GameObjects.h"
                                              "LevelMenu.h"
                                              "Menu.h"
                                              "Resources.h"
                                              "Timer.h"

                                              "playersInclude/Players.h"
                                              "playersInclude/Heavy.h"
                                              "playersInclude/Light.h"
                                              "playersInclude/Simple.h"
                                              
                                              "objectsInclude/Box.h"
                                              "objectsInclude/Stairs.h"
                                              "objectsInclude/StaticObjects.h"
                                              "objectsInclude/Stick.h"
                                              "objectsInclude/Switch.h"
                                                
                                              "Macros.h"
                                              )