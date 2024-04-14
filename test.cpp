#include "pch.h"

            //Unit Test
class RainsensorTest : public ::testing::Test {
protected:
    Rain_Sensor raintype;
};

TEST_F(RainsensorTest, ValuesInRange) {
    // Setăm o valoare aleatorie o singură dată
    raintype.SetValue();
    float valuenow = raintype.GetValue();

    // Test pentru valori de fara  ploaie
    if (valuenow >= 0.0 && valuenow <= 1.99) {
        EXPECT_GE(valuenow, 0.0);
        EXPECT_LE(valuenow, 1.99);
        std::cout << "Valoarea generata (" << valuenow << ") se încadreaza no rain .";
    }
    // Test pentru valori de ploaie reduse
    else if (valuenow >= 2.0 && valuenow <= 4.99) {
        EXPECT_GE(valuenow, 2.0);
        EXPECT_LE(valuenow, 4.99);
        std::cout << "Valoarea generata (" << valuenow << ") se încadreaza în low .";
    }
    // Test pentru valori de ploaie mari
    else if (valuenow >= 5.0 && valuenow <= 12.0) {
        EXPECT_GE(valuenow, 5.0);
        EXPECT_LE(valuenow, 12.0);
        std::cout<< "Valoarea generata (" << valuenow << ") se încadreaza în high .";
    }
    // Afișăm un mesaj de eroare în cazul în care valoarea nu se încadrează în niciun interval
    else {
        FAIL() << "Valoarea generata (" << valuenow << ") nu se încadreaza în niciun interval .";
    }
}

// Integration Test






TEST_F(WiperTestFixture, GivenAutomaticSwitch_WhenRainSensorReadings_ThenWiperBehaviorCorrect) {

    SetUp();
    float rainSensorReading = GetRainSensor();
    CalculateRainState();
    // Pass criteria: software requirement 2.4 a-c are met
    Manager_Motor mr = Manager_Motor (Getmansw());
    mr.SetWiperMotor();
    mr.SetRain();
   
   // auto result = GetmanswResult();
     if (rainSensorReading >= 0.0 && rainSensorReading <= 1.99) {

       EXPECT_EQ(mr.GetWipst().GetWiperSpeed(), WiperSpeed::None);
        EXPECT_EQ(mr.GetRain().GetRain(), RainState::Norain);
       // std::cout << "Valoarea generata (" << std::get<0>(result) << ", " << std::get<1>(result) << ") se încadreaza no rain .";
    }
    // Test pentru valori de ploaie reduse
    else if (rainSensorReading >= 2.0 && rainSensorReading <= 4.99) {

         EXPECT_EQ(mr.GetWipst().GetWiperSpeed(), WiperSpeed::LowSpeed);
         EXPECT_EQ(mr.GetRain().GetRain(), RainState::LowRain);
        ///std::cout << "Valoarea generata (" << std::get<0>(result) << ", " << std::get<1>(result) << ") se încadreaza în low .";
    }
    // Test pentru valori de ploaie mari
    else if (rainSensorReading >= 5.0 && rainSensorReading<= 12.0) {

         EXPECT_EQ(mr.GetWipst().GetWiperSpeed(), WiperSpeed::HighSpeed);
         EXPECT_EQ(mr.GetRain().GetRain(), RainState::HighRain);
        // std::cout << "Valoarea generata (" << std::get<0>(result) << ", " << std::get<1>(result) << ") se încadrează în high.";
    }
    // Afișăm un mesaj de eroare în cazul în care valoarea nu se încadrează în niciun interval
    else {
         ADD_FAILURE();// << "Valoarea generata (" << std::get<0>(result) << ", " << std::get<1>(result) << ") nu se încadreaza în niciun interval.";
    }
}
