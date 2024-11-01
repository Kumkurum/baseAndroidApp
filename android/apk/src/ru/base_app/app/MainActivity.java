package ru.base_app.app;//Это должно совпадать с путём до активити

import org.qtproject.qt.android.bindings.QtActivity;
import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.Window;
import android.view.WindowManager;
import android.view.View;

public class MainActivity extends QtActivity//так как в манифесте написано
{
    private static final String TAG = "BaseAndroidApp";
    private static Context activityContext = null;//храним наш контекст
    private Intent serviceIntent = null; // храним наш сервис, что б его потом грохнуть

    //Тот метод что зарегистрировали в ++ и теперь можем тут дёрать его
    private static native void formJavaToCpp(boolean status);
    //Обработка того что прилетит из ++
    public void fromCppToJava(int count) {
        Log.i(TAG, "fromCppToJava");
        formJavaToCpp(true);
    }
    @Override
	public void onCreate(Bundle savedInstanceState){
        Log.i(TAG, "Activity: Create");
        activityContext = this;
        getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_VISIBLE | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
        super.onCreate(savedInstanceState);
        serviceIntent = new Intent(this, MainService.class);
        startService(serviceIntent);


// 		   Window window = getWindow();
//         window.clearFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS);
//         window.clearFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_NAVIGATION);
//         window.addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS);
    }

    @Override
    public void onResume(){
    	super.onResume();
    	Log.d(TAG, "Activity: onResume");
    }


    @Override
    public void onPause() {
    Log.d(TAG, "Activity: onPause");
        super.onPause();
    }

	@Override
	public void onStop(){
		Log.d(TAG, "Activity: onStop");
		super.onStop();
	}

    @Override
    public void onDestroy() {
        Log.i(TAG, "Activity: Destroying");
        stopService(serviceIntent);
        super.onDestroy();
    }

}
