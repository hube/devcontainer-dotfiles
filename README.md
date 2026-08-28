# About

This repository contains dotfiles used in configuring [Dev Containers][1]. The
`devcontainer` CLI can automatically install dotfiles after starting a Dev
Container when provided the `--dotfiles-repository` option, e.g.

`devcontainer up --dotfiles-repository https://github.com/hube/devcontainer-dotfiles`

See additional information about this feature with `devcontainer up --help`

[1]: https://containers.dev/

## Git identities

Commits are attributed to one of two GitHub accounts, chosen automatically by
the account that owns the remote of the repository being committed to:

- **`hube`** — the default, and what every repository outside `hube-ai` uses.
- **`hube-ai`** — repositories under that account, where an agent is the primary
  author rather than a co-author.

The choice is a conditional include in `.gitconfig` keyed on the remote URL, so
a clone is attributed correctly from the moment it exists and there is no
per-repository step to remember.

**Each identity signs with its own key, and a signature verifies only against
the account that key is registered to.** GitHub resolves a commit's signature
against its *committer*, so a commit committed as one identity and signed with
the other's key is rejected as unverified — while `git log --show-signature`
reports it as a good signature locally. The `verification` field returned by the
GitHub API is what distinguishes the two.

This repository carries only the public halves. **Both private keys must be
loaded in the host's SSH agent**, which the container reaches through the
forwarded agent socket; the keys are never copied into the container and do not
need to be.
