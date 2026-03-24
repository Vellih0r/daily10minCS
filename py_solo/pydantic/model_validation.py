from pydantic import BaseModel, model_validator, ValidationError
from typing import Union, Any

class AllOptionalAfterModel(BaseModel):
    param1: Union[str, None] = None
    param2: Union[str, None] = None
    param3: Union[str, None] = None

    @model_validator(mode="after")
    def there_must_be_one(self):
        if not (self.param1 or self.param2 or self.param3):
            raise ValidationError("One paramener must be specified")
        return self

class AllOptionalBeforeModel(BaseModel):
    param1: Union[str, None] = None
    param2: Union[str, None] = None
    param3: Union[str, None] = None

    @model_validator(mode="before")
    @classmethod
    def there_must_be_one(cls, data: Any):
        if not (data["param1"] or data["param2"] or data["param3"]):
            raise ValidationError("One parameter must be specified")
        return data

