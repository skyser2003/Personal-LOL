{
  "targets" : [
      {
          "target_name" : "main",
          "sources" : [
			  "<!@(node -p \"require('fs').readdirSync('./src').map(f => `src/${f}`).join(' ')\")",
			  "<!@(node -p \"require('fs').readdirSync('../RiotApi/src').map(f => `../RiotApi/src/${f}`).join(' ')\")",
			  "<!@(node -p \"require('fs').readdirSync('../external/libcurl/lib').map(f => `../external/libcurl/lib/${f}`).join(' ')\")"
		  ],
		  "include_dirs": [
		  	  "pch",
			  "header",
			  "../external/crow",
			  "../external/boost",
			  "../external/libcurl/include",
			  "../RiotApi/header",
			  "../RiotApi/pch",
			  "C:/Program Files (x86)/Microsoft Visual Studio/2017/Professional/VC/Tools/MSVC/14.11.25503/atlmfc/include/",
			  "C:/Program Files (x86)/Windows Kits/10/Include/10.0.17134.0/ucrt"
		  ],
		  "libraries": [ "<!@(node -p \"require('fs').readdirSync('../external/boost/stage/lib')" +
		  ".filter(f => /mt-x64/.test(f))" +
		  ".map(f => `../../external/boost/stage/lib/${f}`).join(' ')\")" ],
		  "conditions": [
          	  [
				  'OS=="linux"', {
              	      "CFLAGS_CC": [
                  	  	  "-std=c++17"
              	      ]
			      },
				  'OS=="windows"', {
					  
				  }
			  ]
		  ],
		  "configurations": {
            "Debug": {
                "msvs_settings": {
                    "VCCLCompilerTool": {
                        "RuntimeLibrary": "3" # /MDd
                    },
                },
            },
            "Release": {
                "msvs_settings": {
                    "VCCLCompilerTool": {
                        "RuntimeLibrary": "2" # /MD
                    },
                },
            },
          },
		  "msvs_settings": {
			"VCCLCompilerTool": {
				"AdditionalOptions": [
				"/GR",
				"/EHsc",
				"/std:c++latest",
				]
			}
		  }
      }
   ]
}