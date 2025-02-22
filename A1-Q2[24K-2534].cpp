#include <iostream>
#include <string>

using namespace std;

class Robot {
    string Rname;
    int Rhits;

public:
    Robot() : Rhits(0) {};

    void hitBall(int &ballX, int &ballY, const string &direction)
    {
        if (direction == "up")
        {
            ballY += 1;
        }
        else if (direction == "down")
        {
            ballY -= 1;
        }
        else if (direction == "left")
        {
            ballX -= 1;
        }
        else if (direction == "right")
        {
            ballX += 1;
        }
        Rhits++;
    }

    int getHits()
    {
        return Rhits;
    }

    string getName()
    {
        return Rname;
    }

    void setName(const string &name)
    {
        Rname = name;
    }

    void resetHits()
    {
        Rhits = 0;
    }
};

class Ball {
    int x;
    int y;

public:
    Ball() : x(0), y(0) {}

    int &getX()
    {
        return x;
    }

    int &getY()
    {
        return y;
    }

    string getPosition()
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

    void setPosition(int newX, int newY)
    {
        x = newX;
        y = newY;
    }
};

class Goal {
public:
    int goalX, goalY;

    Goal() : goalX(3), goalY(3) {}

    bool isGoalReached(int ballX, int ballY)
    {
        return ballX == goalX && ballY == goalY;
    }
};

class Team {
    string teamName;
    Robot player;

public:
    Team(string teamname, Robot r)
    {
        teamName = teamname;
        player = r;
    }

    string getTeamName()
    {
        return teamName;
    }
    Robot &getPlayer()
    {
        return player;
    }
};

class Game {
    Team teamOne = {"Anas", Robot()};
    Team teamTwo = {"Nafees", Robot()};
    Ball ball;
    Goal goal;

public:
    Game(Goal g) : goal(g) {}

    void startGame()
    {
        cout << "Game started between " << teamOne.getTeamName() << " and " << teamTwo.getTeamName() << endl;
    }

    void play(Team &team)
    {
        string direction;
        cout << team.getTeamName() << "'s turn. Enter direction (up, down, left, right): ";
        cin >> direction;

        team.getPlayer().hitBall(ball.getX(), ball.getY(), direction);

        cout << "Ball moved to position " << ball.getPosition() << endl;

        if (goal.isGoalReached(ball.getX(), ball.getY()))
        {
            cout << "Goal reached by " << team.getTeamName() << endl;
        }
    }

    void declareWinner()
    {
        int hitsTeamOne = teamOne.getPlayer().getHits();
        int hitsTeamTwo = teamTwo.getPlayer().getHits();

        cout << "Hits by " << teamOne.getTeamName() << ": " << hitsTeamOne << endl;
        cout << "Hits by " << teamTwo.getTeamName() << ": " << hitsTeamTwo << endl;

        if (hitsTeamOne < hitsTeamTwo)
        {
            cout << teamOne.getTeamName() << " wins!" << endl;
        }
        else if (hitsTeamOne > hitsTeamTwo)
        {
            cout << teamTwo.getTeamName() << " wins!" << endl;
        }
        else
        {
            cout << "It's a tie!"<< endl;
        }
    }

    Team &getTeamOne()
    {
        return teamOne;
    }

    Team &getTeamTwo()
    {
        return teamTwo;
    }

    Ball &getBall()
    {
        return ball;
    }
};

int main()
{

cout << "              24K-2534" << endl;
cout << "         Anas Muhammad Khan" << endl;
cout << endl;
    Goal goal;
    Game game(goal);

    game.startGame();

    while (true)
    {
        game.play(game.getTeamOne());
        if (goal.isGoalReached(game.getBall().getX(), game.getBall().getY()))
            break;

        game.play(game.getTeamTwo());
        if (goal.isGoalReached(game.getBall().getX(), game.getBall().getY()))
            break;
    }

    game.declareWinner();

    return 0;
}
