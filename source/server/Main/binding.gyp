{
  "targets" : [
      {
          "target_name" : "main",
          "sources" : [
			  "<!@(node -p \"require('fs').readdirSync('./src').map(f => 'src/'+f).join(' ')\")",
			  "<!@(node -p \"require('fs').readdirSync('./pch').map(f => 'pch/'+f).join(' ')\")"
		  ],
		  "include_dirs": [
		  	  "pch",
			  "header",
			  "../external/crow",
			  "../external/boost",
			  "../external/libcurl/include",
			  "../RiotApi/header"
		  ]
      }
   ]
}