from dataclasses import dataclass

@dataclass
class ProblemModel:
    id: int
    title: str
    descrition: str
    topics: list[str]
    time_limit: str
    input_format: str
    output_format: str
    cases_test: list[dict]