bool isAccelerating = false;
int arrayMap[70];


void run(){
  processMapValue(arrayMap, 5);

}


void FuzzyPID() {

  if (!isAccelerating) {
    //PID();
  }
}

void mapping() {
  int n = 0;

  bool sensorMap = gpio_get(SENSOR_MAP) > THRESHOLD_VALUE;
  bool sensorStop = gpio_get(SENSOR_STOP) > THRESHOLD_VALUE;

  if (sensorMap == true && sensorStop == false) {
    arrayMap[n] = 1;
    if (n > 0) {
      arrayMap[n - 1] = 0;
    }
    n += 1;
  }
}

void processMapValue(int arrayMap[], int take) {
  if (arrayMap[take] == 1) {
    isAccelerating = true;
    turbine(minBuoyancy);
    motors(maxSpeed, maxSpeed);
  } else {
    for (int brakeTimer = 0; brakeTimer < 100; brakeTimer++) {
      turbine(maxBuoyancy);
      motors(brake, brake);
    }
    isAccelerating = false;
  }
}
