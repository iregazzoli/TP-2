To compile this application use `$ make ` or `$ make main`

If you prefer to compile by using the command g++ I'll spare you the trouble, the command is:
`g++ -Wall -Werror -Wconversion -o main main.cpp building.cpp city.cpp tile.cpp inaccesible_tile.cpp buildable_tile.cpp passable_tile.cpp building_handler.cpp map.cpp material_handler.cpp record.cpp utils.cpp menu.cpp material.cpp mine.cpp school.cpp factory.cpp obelisk.cpp sawmill.cpp power_plant.cpp file_utils.cpp empty_passable_tiles.cpp`
And then just run `$ ./main`


If the map doesn't print aligned in your terminal, you can go to file **constant.h** and add or erase extra spaces on the constants icons.
