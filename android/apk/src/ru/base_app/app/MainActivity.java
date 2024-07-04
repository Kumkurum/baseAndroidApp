package ru.base_app.app;//Это должно совпадать с путём до активити

import org.qtproject.qt.android.bindings.QtActivity;
import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

public class MainActivity extends QtActivity//так как в манифесте написано
{
   private static final String TAG = "BaseAndroidApp";

    @Override
	public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        Log.i(TAG, "Creating");
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        Log.i(TAG, "Destroying");
    }

}
