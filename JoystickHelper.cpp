/*
 * JoystickHelper.cpp
 *
 *  Created on: Apr 26, 2013
 *      Author: Sean
 */

#include <windows.h>
#include <sstream>
#include <stdio.h>
#include <regstr.h>

#include "JoystickHelper.h"

#ifdef _WIN32

// Based on: https://github.com/AlexanderOMara/AIRControl
// Changes the interface but overall it's pretty much the same
// as the code from the above link.
std::string JoystickHelper::getName(unsigned int index)
{
	std::string defaultName = "Joystick" + index;

	index = JOYSTICKID1 + index;
	JOYCAPS caps;

	// Store the joystick capabilities
	bool success = joyGetDevCaps(index, &caps, sizeof(caps)) == JOYERR_NOERROR;

	if (!success) {
		return defaultName;
	}

	// Description of the controller
	char *productKey = (char*)malloc(0);

	// Registry key path
	char subkey[256];

	// Registry keys
	HKEY rootKey;
	HKEY currentKey;

	// Successful read variable
	LONG regSuccess;

	// Used to read in the key
	char keyName[256];
	char keyData[256];
	DWORD keyNameSizeOf;
	std::string controllerDescription = defaultName;

	// Merge the registry paths
	snprintf(subkey, 256, "%s\\%s\\%s", REGSTR_PATH_JOYCONFIG, caps.szRegKey, REGSTR_KEY_JOYCURR);

	regSuccess = RegOpenKeyEx(rootKey = HKEY_LOCAL_MACHINE, subkey, 0, KEY_READ, &currentKey);
	if (regSuccess != ERROR_SUCCESS)
	{
		regSuccess = RegOpenKeyEx(rootKey = HKEY_CURRENT_USER, subkey, 0, KEY_READ, &currentKey);
	}

	if (regSuccess == ERROR_SUCCESS)
	{
		// Create the key name for the current controller
		snprintf(keyName, 256, "Joystick%d%s", index + 1, REGSTR_VAL_JOYOEMNAME);

		// Read in the first registry key data to get the name of the key which holds the controller description
		keyNameSizeOf = sizeof(keyData);
		regSuccess = RegQueryValueEx(currentKey, keyName, NULL, NULL, (LPBYTE)keyData, &keyNameSizeOf);
		RegCloseKey(currentKey);

		if (regSuccess == ERROR_SUCCESS)
		{
			// Create the registry path to the second key which stores the name of the device
			snprintf(subkey, 256, "%s\\%s", REGSTR_PATH_JOYOEM, keyData);

			// Open the second key
			regSuccess = RegOpenKeyEx(rootKey, subkey, 0, KEY_READ, &currentKey);

			if (regSuccess == ERROR_SUCCESS)
			{
				// Read in the second key data
				keyNameSizeOf = sizeof(keyData);
				regSuccess = RegQueryValueEx(currentKey, REGSTR_VAL_JOYOEMNAME, NULL, NULL, NULL, &keyNameSizeOf);

				if (regSuccess == ERROR_SUCCESS)
				{
					// Read the key data into the description
					free(productKey);
					productKey = (char*)malloc(keyNameSizeOf);
					regSuccess = RegQueryValueEx(currentKey, REGSTR_VAL_JOYOEMNAME, NULL, NULL, (LPBYTE) productKey, &keyNameSizeOf);
				}

				// Close the key
				RegCloseKey(currentKey);

				// Set the description
				if (regSuccess == ERROR_SUCCESS)
				{
					controllerDescription = productKey;
					// If the return value is blank, use the fallback
					if (controllerDescription == "")
					{
						controllerDescription = defaultName;
					}
				}
			}
		}
	}
	free(productKey);

	return controllerDescription;
}

#else

std::string getName(unsigned int index)
{
	return "Joystick" + index;
}

#endif
