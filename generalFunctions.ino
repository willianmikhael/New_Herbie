bool isAccelerating = false;  

void FuzzyPID(){

  if(!isAccelerating){
    //PID();
  } else{
    motors(stop,stop);
  }
}

void mapping() {

  int n = 0;
  int map[70];


  bool sensorMap = gpio_get(SENSOR_MAP) > THRESHOLD_VALUE;
  bool sensorStop = gpio_get(SENSOR_STOP) > THRESHOLD_VALUE;


  if (sensorMap == true && sensorStop == false) {
    map[n] = 1;
    if (n > 0) {
      map[n - 1] = 0;
    }
    n += 1;
  }

  if (map[5] == 1) {
    isAccelerating = true;
   // turbine(minBuoyancy);
    motors(maxSpeed, maxSpeed);
  } else {
    isAccelerating = false;
    for (int brakeTimer = 0; brakeTimer < 100; brakeTimer++) {
     // turbine(maxBuoyancy);
      motors(brake, brake);
    }
  }