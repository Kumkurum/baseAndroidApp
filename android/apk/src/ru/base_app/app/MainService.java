package ru.base_app.app;//Это должно совпадать с путём до service

import android.app.Service;
import android.os.IBinder;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import org.qtproject.qt.android.bindings.QtService;

public class MainService extends QtService//Имена везде должны совпадать!!!
{
    private static final String TAG = "BaseAndroidApp";
      @Override
      public void onCreate() {
        Log.i(TAG, "Service: Create");
        super.onCreate();
      }

      @Override
      public void onDestroy() {
        Log.i(TAG, "Service: Destroying");
        super.onDestroy();
      }

      @Override
      public int onStartCommand(Intent intent, int flags, int startId) {
          int ret = super.onStartCommand(intent, flags, startId);

          // Do some work

          return ret;
      }
}