#include <iostream>

using namespace std;

bool isSwordGameMode =  false;

class GameModeBase
{
    public:
        virtual void StartPlay()
        {

        }
};

class ACharacter
{
    public:
        float MovementSpeed = 1.f;
        float GravityScale = 10.f;
        string name = "DefaultCharacter";

        ACharacter()
        {
            MovementSpeed = 1.f;
            GravityScale = 10.f;
            name = "DefaultCharacter";
        }

        virtual string GetName()
        {
            return name;
        }
};

class SwordCharacter : public ACharacter
{
    public:
        int PlayerNum = -1;
        bool isRightFacing = false;

        SwordCharacter()
        {
            MovementSpeed = 4.f;
            GravityScale = 15.f;
            name = "SwordCharacter";
            PlayerNum = 1;
        }
};

class RangeCharacter: public ACharacter
{
    public:
        int PlayerNum = -1;
        bool isRightFacing = false;

        RangeCharacter()
        {
            MovementSpeed = 2.f;
            GravityScale = 6.f;
            name = "RangeCharacter";
            PlayerNum = 2;
        }
};

class IParentGameMode
{
    public:
        virtual ACharacter* GetPlayerOne() = 0;
        virtual ACharacter* GetPlayerTwo() = 0;
        virtual void SetPlayerOne(ACharacter* NewPlayer) = 0;
        virtual void SetPlayerTwo(ACharacter* NewPlayer) = 0;
        virtual void SetPlayerOneNum(int Num) = 0;
        virtual void SetPlayerTwoNum(int Num) = 0;
        ACharacter* PlayerOne;
        ACharacter* PlayerTwo;
        virtual void SetRightFacing(int PNum, bool RightFacing) = 0;
};

class SwordGameMode : public GameModeBase, public IParentGameMode
{
        public:
        SwordGameMode()
        {
            PlayerOne = nullptr;
            PlayerTwo = nullptr;
        }
        virtual ACharacter* GetPlayerOne() {return PlayerOne;}
        virtual ACharacter* GetPlayerTwo() {return PlayerTwo;}
        virtual void SetPlayerOne(ACharacter* NewPlayer) {PlayerOne = NewPlayer;}
        virtual void SetPlayerTwo(ACharacter* NewPlayer) {PlayerTwo = NewPlayer;}
        virtual void SetPlayerOneNum(int Num)
        {
            SwordCharacter* SwordPlayerCharacter = dynamic_cast<SwordCharacter*>(PlayerOne);
            SwordPlayerCharacter->PlayerNum = Num;
        }
        virtual void SetPlayerTwoNum(int Num)
        {
            SwordCharacter* SwordPlayerCharacter = dynamic_cast<SwordCharacter*>(PlayerTwo);
            SwordPlayerCharacter->PlayerNum = Num;
        }
        ACharacter* PlayerOne;
        ACharacter* PlayerTwo;
        virtual void SetRightFacing(int PNum, bool RightFacing)
        {
            ACharacter* PlayerCharacter = PlayerOne;
            if(PNum == 2)
                PlayerCharacter = PlayerTwo;
                
            SwordCharacter* SwordPlayerCharacter = dynamic_cast<SwordCharacter*>(PlayerCharacter);
            SwordPlayerCharacter->isRightFacing = RightFacing;
        }
};

class RangeGameMode : public GameModeBase, public IParentGameMode
{
        public:
        RangeGameMode()
        {
            PlayerOne = nullptr;
            PlayerTwo = nullptr;
        }
        virtual ACharacter* GetPlayerOne() {return PlayerOne;}
        virtual ACharacter* GetPlayerTwo() {return PlayerTwo;}
        virtual void SetPlayerOne(ACharacter* NewPlayer) {PlayerOne = NewPlayer;}
        virtual void SetPlayerTwo(ACharacter* NewPlayer) {PlayerTwo = NewPlayer;}
        virtual void SetPlayerOneNum(int Num)
        {
            RangeCharacter* RangePlayerCharacter = dynamic_cast<RangeCharacter*>(PlayerOne);
            RangePlayerCharacter->PlayerNum = Num;
        }
        virtual void SetPlayerTwoNum(int Num)
        {
            RangeCharacter* RangePlayerCharacter = dynamic_cast<RangeCharacter*>(PlayerTwo);
            RangePlayerCharacter->PlayerNum = Num;
        }
        ACharacter* PlayerOne;
        ACharacter* PlayerTwo;
        virtual void SetRightFacing(int PNum, bool RightFacing)
        {
            ACharacter* PlayerCharacter = PlayerOne;
            if(PNum == 2)
                PlayerCharacter = PlayerTwo;

            RangeCharacter* RangePlayerCharacter = dynamic_cast<RangeCharacter*>(PlayerCharacter);
            RangePlayerCharacter->isRightFacing = RightFacing;
        }
};

class World
{
    public:
        World()
        {
            if(isSwordGameMode)
                GameMode = new SwordGameMode();
            else
                GameMode = new RangeGameMode();
        }

        GameModeBase* GetGameMode()
        {
            return GameMode;
        }

        GameModeBase* GameMode;
};

void SelectGameMode()
{
    int GameModeNum = -1;
    std::cout<<"Press 1 to start Sword Game Mode, 2 to start Range Game Mode"<<std::endl;
    std::cin>>GameModeNum;
    if(GameModeNum == 1) isSwordGameMode = true;
    else isSwordGameMode = false;
}

int main()
{
    SelectGameMode();

    World* world = new World();
    IParentGameMode* gameMode;

    if(isSwordGameMode)
    {
        gameMode = dynamic_cast<SwordGameMode*>(world->GetGameMode());
    }
    else
    {
        gameMode = dynamic_cast<RangeGameMode*>(world->GetGameMode());
    }

    SwordCharacter* SwordPlayerCharacter1 = new SwordCharacter();
    RangeCharacter* RangePlayerCharacter1 = new RangeCharacter();
    SwordCharacter* SwordPlayerCharacter2 = new SwordCharacter();
    RangeCharacter* RangePlayerCharacter2 = new RangeCharacter();

    if(isSwordGameMode)
    {
        gameMode->SetPlayerOne(SwordPlayerCharacter1);
        gameMode->SetPlayerTwo(SwordPlayerCharacter2);
        gameMode->SetPlayerOneNum(1);
        gameMode->SetPlayerTwoNum(2);
        gameMode->SetRightFacing(1, true);

        string P1Side = dynamic_cast<SwordCharacter*>(gameMode->GetPlayerOne())->isRightFacing ? "Right" : "Left";
        string P2Side = dynamic_cast<SwordCharacter*>(gameMode->GetPlayerOne())->isRightFacing ? "Left" : "Right";

        cout<<endl;
        cout<<"CharacterName: "<<gameMode->GetPlayerOne()->GetName()<<endl;
        cout<<"Player 1 is facing towards "<<P1Side<<endl;
        cout<<"Player 2 is facing towards "<<P2Side<<endl;
        cout<<endl;
    }
    else
    {
        gameMode->SetPlayerOne(RangePlayerCharacter1);
        gameMode->SetPlayerTwo(RangePlayerCharacter2);
        gameMode->SetPlayerOneNum(1);
        gameMode->SetPlayerTwoNum(2);
        gameMode->SetRightFacing(1, true);

        string P1Side = dynamic_cast<RangeCharacter*>(gameMode->GetPlayerOne())->isRightFacing ? "Right" : "Left";
        string P2Side = dynamic_cast<RangeCharacter*>(gameMode->GetPlayerOne())->isRightFacing ? "Left" : "Right";

        cout<<endl;
        cout<<gameMode->GetPlayerOne()->GetName()<<endl;
        cout<<"Player 1 is facing towards "<<P1Side<<endl;
        cout<<"Player 2 is facing towards "<<P2Side<<endl;
        cout<<endl;
    }
    
}