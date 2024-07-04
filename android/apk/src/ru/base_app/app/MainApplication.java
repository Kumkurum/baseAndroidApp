package ru.base_app.app;//Это должно совпадать с путём до application

import android.content.Intent;
import android.os.Build;

import org.qtproject.qt.android.bindings.QtApplication;

public class MainApplication extends QtApplication
{
	@Override
	public void onCreate()
	{
		super.onCreate();

		//if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
		//    startForegroundService(new Intent(this, MetronomeService.class));
		//} else {
		//	startService(new Intent(this, MetronomeService.class));
		//}
	}
}