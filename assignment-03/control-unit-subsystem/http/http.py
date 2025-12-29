import requests
from typing import Any, Dict, Optional


class HTTPClient:
    """Simple HTTP client for posting JSON records to DBS.

    Usage:
        client = HTTPClient(timeout=5)
        resp = client.post_record(url, record)
    """

    def __init__(self, timeout: int = 5, session: Optional[requests.Session] = None):
        self.timeout = timeout
        self.session = session or requests.Session()

    def post_record(self, db_url: str, record: Dict[str, Any], timeout: Optional[int] = None) -> requests.Response:
        """POST a JSON record to DBS. Returns the Response.

        db_url: full URL where DBS accepts records (e.g. http://dbs.example/api/records)
        """
        t = timeout if timeout is not None else self.timeout
        resp = self.session.post(db_url, json=record, timeout=t)
        resp.raise_for_status()
        return resp
