from datetime import datetime
class Solution:
    def dayOfYear(self, date: str) -> int:
        dt = datetime.strptime(date, "%Y-%m-%d")
        return dt.timetuple().tm_yday

