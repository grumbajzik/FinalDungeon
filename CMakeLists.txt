cmake_minimum_required(VERSION 3.23)
project(Dungeon)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dungeon main.cpp Game.cpp Game.h Menu/Button.cpp Menu/Button.h Menu/Menu.cpp Menu/Menu.h Options.cpp Options.h Map/Tile.cpp Map/Tile.h
        Menu/StartGameButton.cpp
        Menu/StartGameButton.h
        Menu/EditPlayerSkin.cpp
        Menu/EditPlayerSkin.h
        Menu/ExitGame.cpp
        Menu/ExitGame.h
        Player/Player.cpp
        Player/Player.h
        Player/Archer.cpp
        Player/Archer.h
        Player/Warrior.cpp
        Player/Warrior.h
        EnemyObject/Monster/ArtilleryMonster.cpp
        EnemyObject/Monster/ArtilleryMonster.h
        EnemyObject/Monster/WeakArtilleryEnemy.cpp
        EnemyObject/Monster/WeakArtilleryEnemy.h
        EnemyObject/Monster/StrongArtilleryEnemy.cpp
        EnemyObject/Monster/StrongArtilleryEnemy.h
        EnemyObject/Monster/CloseCombatEnemy.cpp
        EnemyObject/Monster/CloseCombatEnemy.h
        EnemyObject/Monster/WeakCloseCombatEnemy.cpp
        EnemyObject/Monster/WeakCloseCombatEnemy.h
        EnemyObject/Monster/StrongCloseCombatEnemy.cpp
        EnemyObject/Monster/StrongCloseCombatEnemy.h
        EnemyObject/Monster/MonsterFactory.cpp
        EnemyObject/Monster/MonsterFactory.h
        EnemyObject/Monster/WeakMonsterFactory.cpp
        EnemyObject/Monster/WeakMonsterFactory.h
        EnemyObject/Monster/StrongMonsterFactory.cpp
        EnemyObject/Monster/StrongMonsterFactory.h
        Menu/DifficultyOfGameButton.cpp
        Menu/DifficultyOfGameButton.h
        Menu/HowToPlayButton.cpp
        Menu/HowToPlayButton.h
        Map/Room.h
        Map/Room.cpp
        EnemyObject/Trap/StaticTrap.cpp
        EnemyObject/Trap/StaticTrap.h
        Enums/PlayerType.cpp Enums/PlayerType.h Enums/FactoryType.cpp Enums/FactoryType.h Map/Map.cpp Map/Map.h)
