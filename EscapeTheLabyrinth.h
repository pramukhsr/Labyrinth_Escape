#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Pramukh Sreerama";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "SENEEWSESSNNWSWWSE";
const string kPathOutOfTwistyMaze = "WESWEWSWSE";

bool isPathToFreedom(MazeCell *start, const string& moves) {
    int p = 0;
    int s = 0;
    int w = 0;
    if (start->whatsHere == "Potion") {
        p++;
    }
    if (start->whatsHere == "Wand") {
        w++;
    }
    if (start->whatsHere == "Spellbook") {
        s++;
    }
    for (auto x: moves) {
        if (x != 'N' &&x != 'S' &&x != 'E' &&x != 'W') {
            return false;
        }
    }
    for(auto x: moves) {
        if(x == 'N' && start->north != nullptr) {
            start = start->north;
            if(start->whatsHere == "Potion") { p++; }
            if(start->whatsHere == "Spellbook") { s++; }
            if(start->whatsHere == "Wand") { w++; }
        }
        else if (x == 'S' && start->south != nullptr) {
            start = start->south;
            if(start->whatsHere == "Potion") { p++; }
            if(start->whatsHere == "Spellbook") { s++; }
            if(start->whatsHere == "Wand") { w++; }
        }
        else if (x == 'E' && start->east != nullptr) {
            start = start->east;
            if(start->whatsHere == "Potion") { p++; }
            if(start->whatsHere == "Spellbook") { s++; }
            if(start->whatsHere == "Wand") { w++; }
        }
        else if (x == 'W' && start->west != nullptr) {
            start = start->west;
            if(start->whatsHere == "Potion") { p++; }
            if(start->whatsHere == "Spellbook") { s++; }
            if(start->whatsHere == "Wand") { w++; }
        } else { return false; }
    }
    if(p > 0 && s > 0 && w > 0) {
        return true;
    }
    return false;
}
