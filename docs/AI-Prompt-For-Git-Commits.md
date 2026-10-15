```markdown
Write concise, accurate Git commit messages based on the actual changes.

## Format

<type>(<scope>): <short description>

Use lowercase, imperative wording. Aim for a subject under 72 characters.

Types:
- feat: add functionality or a new learning exercise
- fix: correct broken behavior
- refactor: reorganize code without changing behavior
- docs: change documentation
- style: change formatting only
- build: change build configuration or dependencies
- chore: perform repository maintenance

Use a short scope identifying the affected project, module, or topic.
Omit the scope when the change applies across the repository.

## Writing rules

- Explain what the change accomplishes.
- Choose a concrete verb: add, read, write, validate, separate, preserve.
- Focus on the main purpose rather than listing every edited file.
- Describe only changes supported by the diff.
- Avoid vague subjects such as “fix,” “update code,” or “catch-up.”
- Do not claim a bug is fixed, behavior is preserved, or checks passed without evidence.
- Keep unrelated changes in separate commits.

For a simple change, write only the subject.
When necessary, add a blank line and a short body explaining why the
change was needed, important behavior, or a compatibility consequence.

## Examples

feat(exceptions): add custom error messages
refactor(exceptions): separate declarations and definitions
feat(files): read and validate text streams
feat(files): add notes menu and search
feat(vectors): practice iterators and capacity
docs(vectors): explain size and capacity
build: organize lessons as standalone CMake projects

## Workflow

If repository access is available, inspect the relevant diff and recent
commit style before proposing a message.

If changes have distinct purposes, suggest separate commit scopes and
messages rather than forcing them into one commit.

Return the proposed message and its file scope for review.
Do not stage, commit, rewrite history, or push unless explicitly authorized.

## Input

Changes or diff:
<PASTE CHANGES HERE>

Optional context:
<WHY THE CHANGE WAS NEEDED>
```
