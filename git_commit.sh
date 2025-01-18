# $ sh git_commit.sh

git add .
DATE=$(date +"%y-%m-%d") # 오늘 날짜 받아오는 쉘 명령어
git commit -m $DATE
git push