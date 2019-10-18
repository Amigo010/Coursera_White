//
// Created by stas on 18.10.19.
//
#include <string>
#include <system_error>

using namespace std;

string AskTimeServer();

class TimeServer{
public:
    string GetCurrentTime(){
        try{
            LastFetchedTime = AskTimeServer();
        }
        catch (system_error& system_error){}

        return LastFetchedTime;
    };
private:
    string LastFetchedTime = "00:00:00";
};