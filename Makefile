.PHONY: clean
clean:
	powershell -Command "Get-ChildItem -Recurse -Filter *.exe | Remove-Item -Force"