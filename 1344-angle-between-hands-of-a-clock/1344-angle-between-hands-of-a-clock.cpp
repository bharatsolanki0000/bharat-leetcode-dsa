class Solution {
public:
    double angleClock(int hour, int minutes) {

        double baseMinute=(minutes*6);

        double baseHour=(hour*30)%360;

        double tempHour=minutes*0.5;

        double hourDis=baseHour+tempHour;
        double minuteDis=baseMinute;

        double ans=abs(hourDis-minuteDis);
        return min(ans, 360-ans);
    }
};