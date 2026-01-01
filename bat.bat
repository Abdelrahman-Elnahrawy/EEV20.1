@echo off
echo ==========================================
echo   EEV20.1 - GitHub Pages 3D Setup Script
echo ==========================================
echo.

REM -------- CHECK DOCS FOLDER --------
if not exist docs (
    echo Creating docs folder...
    mkdir docs
) else (
    echo docs folder already exists.
)

REM -------- CREATE index.html --------
echo Creating index.html...

(
echo ^<!DOCTYPE html^>
echo ^<html lang="en"^>
echo ^<head^>
echo   ^<meta charset="UTF-8"^>
echo   ^<title^>EEV20.1 - 3D Model^</title^>
echo   ^<script type="module" src="https://unpkg.com/@google/model-viewer/dist/model-viewer.min.js"^>^</script^>
echo   ^<style^>
echo     body { margin:0; background:#111; color:#fff; font-family:Arial; text-align:center; }
echo     h1 { margin:20px 0; }
echo     model-viewer { width:100vw; height:80vh; }
echo     a { color:#4fc3f7; text-decoration:none; }
echo   ^</style^>
echo ^</head^>
echo ^<body^>
echo   ^<h1^>EEV20.1 – Interactive 3D Model^</h1^>
echo   ^<model-viewer src="Product_vision.glb" auto-rotate camera-controls exposure="1.1" shadow-intensity="1"^>^</model-viewer^>
echo   ^<p^>^<a href="Product_vision.glb" download^>⬇ Download GLB^</a^>^</p^>
echo ^</body^>
echo ^</html^>
) > docs\index.html

REM -------- COPY GLB FILES --------
echo.
echo Looking for GLB files...

for %%f in (*.glb) do (
    echo Copying %%f to docs\
    copy "%%f" "docs\" >nul
)

REM -------- DONE --------
echo.
echo ==========================================
echo  DONE!
echo ==========================================
echo.
echo NEXT STEPS:
echo 1. git add docs
echo 2. git commit -m "Add GitHub Pages 3D viewer"
echo 3. git push
echo 4. Go to GitHub:
echo    Settings -> Pages
echo    Branch: main
echo    Folder: /docs
echo.
echo Your 3D page will be at:
echo https://USERNAME.github.io/REPO_NAME/
echo ==========================================
pause
