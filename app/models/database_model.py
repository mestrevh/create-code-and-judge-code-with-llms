from dataclasses import dataclass, field
from typing import List

@dataclass
class DatabaseModel:
    questions_id: List[int] = field(default_factory=list)
    