﻿target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_sources (${CMAKE_PROJECT_NAME} PRIVATE 
                                              "Controller.h"
                                              "World.h"
                                              "Window.h"
                                              "DataDisplay.h"
                                              "Animation.h"
                                              "Audio.h"
                                              "Button.h"
                                              "TitledButton.h"
                                              "Settings.h"
                                              "HighScoreView.h"
                                              "GameObjects.h"
                                              "Screens/Screen.h"
                                              "Screens/HomePageScreen.h"
                                              "Screens/GameScreen.h"
                                              "Screens/LevelMenuScreen.h"
                                              "EndLevelView.h"
                                              "Utilities.h"
                                              "Resources.h"
                                              "Timer.h"
                                              "HighScore.h"
                                              "playersInclude/Players.h"
                                              "playersInclude/Heavy.h"
                                              "playersInclude/Light.h"
                                              "playersInclude/Simple.h"
                                              
                                              "objectsInclude/Box.h"
                                              "objectsInclude/Floor.h"
                                              "objectsInclude/StaticObjects.h"
                                              "objectsInclude/Switch.h"
                                                
                                              "Macros.h"
                                              "DebugDraw.h"
                                              "Factory.h"

                                              "MyContactListener.h"
                                              "CollisionHandler.h"

                                              "objectsInclude/Billboard.h"
                                              "objectsInclude/Door.h"
                                              "objectsInclude/Border.h"
                                              )