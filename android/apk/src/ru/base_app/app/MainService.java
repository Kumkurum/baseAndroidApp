package ru.base_app.app;//Это должно совпадать с путём до service

import android.content.Context;
import android.content.Intent;
import android.util.Log;
import org.qtproject.qt.android.bindings.QtService;

public class MainService extends QtService//Имена везде должны совпадать!!!
{
    private static final String TAG = "BaseAndroidApp";

    @Override
    public void onCreate() {
        super.onCreate();
        Log.i(TAG, "Creating Service");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "Destroying Service");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        int ret = super.onStartCommand(intent, flags, startId);

        // Do some work

        return ret;
    }
}