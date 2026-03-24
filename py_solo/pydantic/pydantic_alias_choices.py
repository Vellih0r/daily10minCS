from pydantic import BaseModel, ConfigDict, AliasGenerator, AliasChoices

aliases = {
    "first_name": AliasChoices("fname", "surname", "forename", "first_name"),
    "last_name": AliasChoices("lname", "family_name", "last_name")
}


class FirstNameChoices(BaseModel):
    model_config = ConfigDict(
        alias_generator=AliasGenerator(
            validation_alias=lambda field_name: aliases.get(field_name, None)
        )
    )
    title: str
    first_name: str
    last_name: str

