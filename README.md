# Flying Stickman Game

# STYLE GUIDE

The style for this project is based on the Google [C++ style guide](https://google.github.io/styleguide/cppguide.html). There are some variations:

## Headers:

  - System header includes come after local header includes
  - Only necessary headers, and all necessary headers, are included in each file

## Indentation:

  Indent your code with 4 spaces. Never use tabs or mix tabs and spaces. In cases of implied line continuation you should align wrapped elements vertically:

    <Class> foo(var_one,
                var_two,
                var_three,
                var_four)

## Naming:

  - ClassName, methodName, ui_action_functions, global_var_name, instance_var_name,
    function_parameter_name, local_var_name

  - Function names, variable names, and filenames should be descriptive; avoid abbreviation. In particular, do not use abbreviations that are ambiguous to the readers. Do not abbreviate by deleting letters within a word.

  ** Names to Avoid: single character names except for counters or iterators **

# EXTENSIONS

## Stage 1

  1. Main Menu screen where the user can select which background they would like to play the game in
  2. Parallax background to establish a scrolling background (stickman is stationary everything else is moving)
  3. Pause menu
    - User can change x position of the stickman as well as the size
    - Can resume play with the selected options
    - Options altered in real-time
  4. Background Music that has a infinite loop
  5. Animation of stickman, stickman is running.

## Stage 2
  1. Stickman can double jump. A variable can be changed to extend this to a triple jump or more. The Stickman also has a configurable jump height.
  2. Recursive Entity lookup. The GameState class has methods that allow the programmer to search the game state hierarchy for game entities by name, or by a substring of their name.

## Stage 3
  1. Mute background music button: In the startDialog there's a button which can be used to mute background music.
  2. Random obstacle placement: The obstacle x coordinate is calculated based on the config plus a random number between 0 and 100.
  3. Random obstacle colour: The obstacle color is random, we don't rely on RGB value in stage2, instead color is randomly generated.
  4. Jump sound effect: When user hit "Space" play a jump sound effect.
  5. Crash sound effect: When player hit an obstacle and he is not in "giant" size, player loses one life and sound effect will be played.
  6. Victory sound effect: When player hit the victory flag, victory music will be played, and a new level starts.
  7. Infinite level: There're infinite levels. The obstacle loop increases when level increases.

# DESIGN PATTERNS

## Stage 1

### Factory method

The game dialog is created by a factory to allow for easy extension. The separation of object construction from object use allows new game dialogs to be created without tight coupling of the start dialog and the game dialog.

### Singleton

The Config class is a singleton to make sure no more than one instance is ever created.

## Stage 2

### Composite pattern

The GameState class stores information about the current game's state. This includes a pointer to an  Entity object, the root of the game state hierarchy. The Entity class is an abstract class that defines pure virtual methods for updating, rendering and retrieving components (such as Colliders) for an object in the game (e.g. an Obstacle). There are two abstract subclasses of Entity: LeafEntity and CompositeEntity. LeafEntity currently does not add any additional functionality to the Entity class, but CompositeEntity allows for the updating and rendering of children Entities. There are three main concrete classes in the scene that have CompositeEntity as an ancestor: StickmanPlayer, Obstacle and EmptyEntity.

### Object adapter

There are two object adapters present in the code.
  1. Configuration is an abstract class, the target. ExtendedConfig (the adapter) accesses the Config singleton (adaptee) to extend the functionality of the Config class.
  2. Player is an abstract class, the target. StickmanPlayer (the adapter) accesses the Stickman object (adaptee) from the config singleton to allow for physics and collision operations.

### Factory method

The GameState class is the product (however instances of it can be created), produced by the createGameState() method in the abstract factory GameStateFactory. Stage2GameStateFactory is a concrete factory that produces Stage2GameState objects, which are concrete products inheriting from GameState. This allows for the customisation of GameState objects, and the easy creation of GameState instances in both the Stage2Game class and the Tester class.

## Stage 3

### Iterator

The Iterator class is an abstract class which has two pure virtual method getNext() and hasNext(). ObstacleIterator class is the concrete implementation of Iterator class. The ObstacleIterable has one method createIterator, which creates an obstacle iterator based on obstacle_data in the config file.
