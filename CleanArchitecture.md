# Clean Architecture — The Complete Revision Book
### For ASP.NET Core Web API + PostgreSQL + EF Core (with a Next.js frontend)

> A single reference you can read once to learn, and reread forever to revise.

---

## Table of Contents

1. [Software Architecture Basics](#1-software-architecture-basics)
2. [What is Clean Architecture?](#2-what-is-clean-architecture)
3. [Why Do We Need Clean Architecture?](#3-why-do-we-need-clean-architecture)
4. [Clean Architecture Principles](#4-clean-architecture-principles)
5. [The Four Main Layers — Overview](#5-the-four-main-layers--overview)
6. [Domain Layer](#6-domain-layer)
7. [Application Layer](#7-application-layer)
8. [Use Cases](#8-use-cases)
9. [Commands and Queries](#9-commands-and-queries)
10. [DTOs (Data Transfer Objects)](#10-dtos-data-transfer-objects)
11. [Repository Pattern](#11-repository-pattern)
12. [Unit of Work](#12-unit-of-work)
13. [Infrastructure Layer](#13-infrastructure-layer)
14. [Entity Framework Core Integration](#14-entity-framework-core-integration)
15. [Entity Configuration](#15-entity-configuration)
16. [Presentation Layer / API Layer](#16-presentation-layer--api-layer)
17. [Dependency Injection](#17-dependency-injection)
18. [Dependency Inversion Principle (DIP)](#18-dependency-inversion-principle-dip)
19. [Complete Project Structure](#19-complete-project-structure)
20. [Project-to-Project Dependencies](#20-project-to-project-dependencies)
21. [Complete End-to-End Example — Twitter Clone](#21-complete-end-to-end-example--twitter-clone)
22. [Complete Code Example — Create Post, End to End](#22-complete-code-example--create-post-end-to-end)
23. [Clean Architecture + Next.js](#23-clean-architecture--nextjs)
24. [Authentication and Authorization](#24-authentication-and-authorization)
25. [Validation](#25-validation)
26. [Error Handling](#26-error-handling)
27. [Testing in Clean Architecture](#27-testing-in-clean-architecture)
28. [Common Anti-Patterns](#28-common-anti-patterns)
29. [Clean Architecture vs Other Architectures](#29-clean-architecture-vs-other-architectures)
30. [Clean Architecture vs Onion Architecture](#30-clean-architecture-vs-onion-architecture)
31. [Clean Architecture vs Vertical Slice Architecture](#31-clean-architecture-vs-vertical-slice-architecture)
32. [MediatR](#32-mediatr)
33. [Generic Repository Debate](#33-generic-repository-debate)
34. [Overengineering](#34-overengineering)
35. [Real-World Industry Perspective](#35-real-world-industry-perspective)
36. [Clean Architecture + Microservices](#36-clean-architecture--microservices)
37. [Practical Development Workflow](#37-practical-development-workflow)
38. [How to Decide Where Code Belongs](#38-how-to-decide-where-code-belongs)
39. [Interview Questions](#39-interview-questions)
40. [Viva / Quick Revision Questions](#40-viva--quick-revision-questions)
41. [Common Interview Traps](#41-common-interview-traps--things-you-should-not-say)
42. [Cheat Sheet](#42-cheat-sheet)
43. [Architecture Diagrams — Reference Set](#43-architecture-diagrams--reference-set)
44. [Practical Exercises](#44-practical-exercises)
45. [Final Mental Model](#45-final-mental-model)
46. [Final Summary](#46-final-summary)

---

# 1. Software Architecture Basics

## 1.1 What is Software Architecture?

**Formal definition:** Software architecture is the set of high-level decisions about how a system is organized — how it is split into parts, how those parts communicate, and what rules govern their dependencies.

**Simple explanation:** It's the "shape" of your code before you write any of it. It answers questions like: *Where does business logic live? What talks to the database? What happens when the UI changes?*

**Analogy:** Think of a house. The architecture is the blueprint — where the walls, plumbing, and electrical wiring go — decided *before* construction. Coding is laying the bricks. You can lay bricks beautifully and still end up with a house that collapses if the blueprint was bad.

**Why it matters:**
- Small scripts barely need architecture — a single file is fine for a 50-line tool.
- As a codebase grows (thousands of files, many developers, years of maintenance), the *shape* of the code determines whether change is cheap or expensive.
- Good architecture makes it possible to change *how* something is done (e.g., swap SQL Server for PostgreSQL) without changing *what* the system does (business rules).

## 1.2 Architecture vs Design vs Coding

| Level | Question it answers | Example |
|---|---|---|
| Architecture | How are the major parts organized and how do they depend on each other? | "Domain must not depend on EF Core." |
| Design | How is a specific class/module structured? | "Should `Post` have a private setter for `Content`?" |
| Coding | How is a specific line of logic written? | "Use a `for` loop or LINQ here?" |

Architecture decisions are the most expensive to reverse. A bad variable name costs seconds to fix. A bad architectural dependency (e.g., business logic hard-wired to a specific database) can cost weeks or months to unwind.

## 1.3 Problems Caused by Poor Architecture

- **Tight coupling** — changing one part breaks unrelated parts.
- **Fragile tests** — you can't test business logic without spinning up a real database.
- **Slow onboarding** — new developers can't find where anything lives.
- **Fear of change** — nobody wants to touch old code because nobody understands the ripple effects.
- **Duplicated logic** — the same validation rule copy-pasted into five controllers.
- **Vendor lock-in** — the whole codebase assumes one specific framework or database forever.

---

# 2. What is Clean Architecture?

**Formal definition:** Clean Architecture (popularized by Robert C. Martin, "Uncle Bob") is a way of organizing code into concentric layers, where **all source-code dependencies point inward**, toward the business logic, and never outward toward frameworks, databases, or UI.

**Simple explanation:** Put your business rules at the center of your application, completely untouched by technical details like "which database" or "which web framework." Everything technical becomes a replaceable detail plugged into the center.

**Analogy:** A power outlet in your wall doesn't care what you plug into it — a lamp, a phone charger, a laptop. The *outlet* (your business logic) defines a stable interface; the *devices* (frameworks, databases) are swappable details that conform to it. It's not the other way around — the wall doesn't rebuild itself to match your lamp.

## 2.1 Main Goals

- **Independence from frameworks** — ASP.NET Core is a detail, not the foundation.
- **Independence from UI** — swap a REST API for GraphQL or a CLI without touching business rules.
- **Independence from the database** — swap PostgreSQL for SQL Server without touching business rules.
- **Testability** — business rules can be tested with zero infrastructure (no database, no web server).
- **Independence from external agencies** — third-party services (email providers, payment gateways) are details.

## 2.2 Problems It Tries to Solve

Clean Architecture directly targets the problems from Section 1.3: tight coupling, hard-to-test business logic, and code that dies the moment you want to change a technical choice.

## 2.3 Core Philosophy

### The Dependency Rule
> Source code dependencies can only point **inward**. Nothing in an inner circle can know anything about an outer circle.

This is *the* rule. Everything else in Clean Architecture exists to support it.

### Separation of Concerns
Each layer has one job. The Domain layer knows about business rules. The Infrastructure layer knows about PostgreSQL. Neither should know the other's job.

### Dependency Inversion
High-level modules (business logic) should not depend on low-level modules (database access). Both should depend on abstractions (interfaces). Covered fully in Section 10.

## 2.4 The Diagram

```
        Presentation
             ↓
        Application
             ↓
          Domain
             ↑
        Infrastructure
```

Read this as: Presentation depends on Application. Application depends on Domain. Infrastructure *also* depends on Domain/Application (via interfaces) — but nothing depends on Infrastructure. Infrastructure is "plugged in from the outside," which is why the arrow points up into the circle rather than the circle depending down into it.

A more traditional concentric version:

```
+-----------------------------------------------------------+
|                      INFRASTRUCTURE                       |
|   +-----------------------------------------------------+ |
|   |                    PRESENTATION                     | |
|   |   +---------------------------------------------+   | |
|   |   |                  APPLICATION                |   | | 
|   |   |   +---------------------------------------+ |   | | 
|   |   |   |                 DOMAIN                | |   | | 
|   |   |   |                                       | |   | | 
|   |   |   +---------------------------------------+ |   | | 
|   |   |                                             |   | | 
|   |   +---------------------------------------------+   | |
|   |                                                     | | 
|   +-----------------------------------------------------+ |
|                                                           |
+-----------------------------------------------------------+

              All arrows of dependency point INWARD only →
```

Domain sits at the center with **zero** dependencies on anything else. Application depends only on Domain. Infrastructure and Presentation depend on Application and Domain — never the reverse.

---

# 3. Why Do We Need Clean Architecture?

## 3.1 The Painful Starting Point

Here's how many ASP.NET Core projects begin — and how they slowly become unmaintainable.

```
Controller
    ↓
Entity Framework Core
    ↓
PostgreSQL
```

A controller action directly uses `DbContext`, and over time absorbs everything:

```csharp
[HttpPost]
public async Task<IActionResult> CreatePost([FromBody] CreatePostRequest request)
{
    // validation logic
    if (string.IsNullOrWhiteSpace(request.Content))
        return BadRequest("Content required");
    if (request.Content.Length > 280)
        return BadRequest("Too long");

    // authentication logic
    var userId = User.FindFirst("sub")?.Value;
    if (userId == null) return Unauthorized();

    // business logic + database access mixed together
    var post = new Post { Content = request.Content, UserId = Guid.Parse(userId), CreatedAt = DateTime.UtcNow };
    _dbContext.Posts.Add(post);
    await _dbContext.SaveChangesAsync();

    // notification logic
    await _emailService.SendNewPostNotificationAsync(post);

    // file upload logic, logging, etc. keep piling on...

    return Ok(post);
}
```

## 3.2 Why This Becomes Problematic

- **Tight coupling** — the controller is glued to EF Core and PostgreSQL. You cannot change either without touching HTTP code.
- **Difficult testing** — to test the 280-character rule, you need a running database and a fake HTTP request. A pure business rule should be testable in milliseconds, with no infrastructure at all.
- **Difficult maintenance** — six months later, nobody remembers all the responsibilities crammed into `CreatePost`.
- **Difficult database migration** — swapping PostgreSQL for another database means touching every controller.
- **Difficult framework changes** — the business rule "post must be ≤ 280 characters" is trapped inside ASP.NET Core-specific code. It can't be reused in a background job or a CLI tool.
- **Large controllers** — controllers grow to thousands of lines, mixing HTTP concerns with business concerns.
- **Duplicate business logic** — the same 280-character check gets copy-pasted into `UpdatePostController`, a mobile API, and an admin tool — and they drift out of sync.
- **Poor separation of concerns** — one method does validation, auth, business rules, persistence, and notifications. A change to any one of these risks breaking the others.

## 3.3 Gradually Refactoring Toward Clean Architecture

**Step 1 — Extract business logic into a Domain entity.**

```csharp
public class Post
{
    public const int MaxContentLength = 280;
    public Guid Id { get; private set; }
    public string Content { get; private set; }
    public Guid UserId { get; private set; }

    public static Post Create(Guid userId, string content)
    {
        if (string.IsNullOrWhiteSpace(content))
            throw new DomainException("Content cannot be empty.");
        if (content.Length > MaxContentLength)
            throw new DomainException($"Content cannot exceed {MaxContentLength} characters.");

        return new Post { Id = Guid.NewGuid(), UserId = userId, Content = content };
    }
}
```

**Step 2 — Extract persistence behind an interface (`IPostRepository`)** owned by the Application layer, implemented by Infrastructure.

**Step 3 — Extract the orchestration into a Use Case (`CreatePostUseCase`)** that calls the Domain entity and the repository interface.

**Step 4 — Shrink the controller** down to: accept HTTP request → call use case → return HTTP response. Nothing else.

```
Controller
     ↓
Use Case
     ↓
Domain
```

This is the essence of the refactor covered in depth throughout the rest of this book.

---

# 4. Clean Architecture Principles

Each principle below follows: **definition → explanation → bad example → good example → why it matters here.**

## 4.1 Separation of Concerns

**Definition:** Each part of the system should be responsible for one concern, and concerns should not be mixed together in the same place.

**Bad:** A controller that validates input, applies business rules, queries the database, and sends emails.

**Good:** Controller handles HTTP only; Use Case handles orchestration; Domain handles business rules; Infrastructure handles technical details.

**Why it matters:** It lets you change one concern (e.g., "how we send emails") without touching unrelated code (e.g., "how we validate a post").

## 4.2 Dependency Inversion

Covered fully in Section 10. In short: depend on abstractions, not concrete implementations, and let outer layers depend on inner layers — never the reverse.

## 4.3 The Dependency Rule

**Definition:** Source-code dependencies always point inward, toward higher-level policies (business rules).

**Bad:** `Domain.Post` references `Microsoft.EntityFrameworkCore`.

**Good:** `Domain.Post` references nothing outside the Base Class Library. `Infrastructure.PostRepository` references `Domain.Post`.

**Why it matters:** This is the rule that makes every other Clean Architecture benefit (testability, replaceability, independence) possible. Break this rule anywhere, and the whole structure starts to unravel.

## 4.4 Single Responsibility Principle (SRP)

**Definition:** A class should have only one reason to change.

**Bad:**
```csharp
public class PostService
{
    public void CreatePost(...) { /* validation */ /* db access */ /* email */ }
}
```
This class changes if validation rules change, if the database changes, or if the email provider changes — three reasons to change.

**Good:** Split into `Post` (validation/business rules), `PostRepository` (persistence), `NotificationService` (email) — each with one reason to change.

**Why it matters in Clean Architecture:** SRP is what naturally produces the layer boundaries. Each layer *is* a responsibility.

## 4.5 Open/Closed Principle (OCP)

**Definition:** Software entities should be open for extension but closed for modification.

**Bad:** A big `switch` statement on `NotificationType` that you edit every time a new notification type is added.

**Good:** An `INotificationSender` interface with one implementation per channel (`EmailNotificationSender`, `SmsNotificationSender`); adding a channel means adding a new class, not editing existing ones.

**Why it matters:** Lets you add new use cases or infrastructure implementations without risking existing, tested code.

## 4.6 Interface Segregation Principle (ISP)

**Definition:** Clients should not be forced to depend on methods they don't use.

**Bad:** One giant `IRepository` with 30 methods, most unused by most callers.

**Good:** Small, focused interfaces — `IPostRepository` with only the methods Posts actually need.

**Why it matters:** Small interfaces are easy to fake in tests and easy to reason about.

## 4.7 Liskov Substitution Principle (LSP)

**Definition:** Subtypes must be substitutable for their base types without breaking correctness.

**Bad:** An `InMemoryPostRepository` used in tests that silently ignores `DeleteAsync`, while the real `PostRepository` actually deletes — tests pass but production behaves differently.

**Good:** Every implementation of `IPostRepository` honors the same contract/behavior.

**Why it matters:** Clean Architecture relies on swapping implementations (real DB vs. in-memory fake) behind the same interface. If substitutes don't behave consistently, that swap becomes dangerous.

## 4.8 Encapsulation

**Definition:** Hiding internal state and exposing only controlled ways to change it.

**Bad:** `public string Content { get; set; }` — anyone can set an invalid 10,000-character string.

**Good:** `public string Content { get; private set; }` with changes only possible through methods that enforce rules (e.g., `Post.Edit(newContent)`).

**Why it matters:** Encapsulation is how the Domain layer *guarantees* business rules are never bypassed.

## 4.9 Abstraction

**Definition:** Exposing only what matters to the consumer while hiding implementation details.

**Example:** `IPostRepository.GetByIdAsync(Guid id)` — the caller doesn't know or care whether this runs a raw SQL query, uses EF Core, or calls an API.

**Why it matters:** Abstraction is the mechanism that makes Dependency Inversion possible.

## 4.10 Low Coupling / High Cohesion

- **Low coupling** = modules don't need to know much about each other's internals.
- **High cohesion** = things that belong together are grouped together (e.g., all Post-related use cases live in one folder).

**Why it matters:** Together, these two qualities are what make a codebase easy to navigate and safe to change — and they're the practical outcome of applying every principle above correctly.

---

# 5. The Four Main Layers — Overview

Before diving deep into each layer (Sections 6-9), here's the map.

| Layer | Purpose | Depends On |
|---|---|---|
| **Domain** | The business itself — entities, rules, value objects | Nothing |
| **Application** | What the system can do — use cases, orchestration | Domain |
| **Infrastructure** | How things are technically implemented — EF Core, PostgreSQL, email, JWT | Application, Domain |
| **Presentation/API** | How the outside world talks to the system — controllers, HTTP | Application, Infrastructure |

For each layer, ask three questions: *What belongs here? What must never be here? What can this layer depend on?*

---

# 6. Domain Layer

The Domain layer is the **core** of Clean Architecture. It represents the business itself — independent of any technology.

## 6.1 What Belongs Here

Entities, Value Objects, Enums, Domain Services, Domain Events, Domain Exceptions, and business rules.

## 6.2 What Does NOT Belong Here

- No EF Core, no `DbContext`, no `[Table]`/`[Column]` attributes tied to a specific ORM
- No ASP.NET Core types (`HttpContext`, `IActionResult`)
- No direct SQL
- No references to Infrastructure or Presentation projects at all

## 6.3 Entities

**Formal definition:** An entity is an object defined primarily by its *identity* (a unique ID) rather than its attributes. Two entities with identical attributes but different IDs are different entities.

**Simple explanation:** An entity is "a thing that matters and persists over time" in your business — a `User`, a `Post`, an `Order`.

**Analogy:** Two people can have the exact same name and birthday, but they are still two different people because each has a unique identity (say, a passport number). That passport number is like the entity's `Id`.

**Software example:**
```csharp
public class User
{
    public Guid Id { get; private set; }
    public string Username { get; private set; }
    public string PasswordHash { get; private set; }

    private User() { } // for ORM materialization only

    public static User Register(string username, string passwordHash)
    {
        if (string.IsNullOrWhiteSpace(username))
            throw new DomainException("Username is required.");

        return new User
        {
            Id = Guid.NewGuid(),
            Username = username,
            PasswordHash = passwordHash
        };
    }

    public void ChangePassword(string newPasswordHash)
    {
        if (string.IsNullOrWhiteSpace(newPasswordHash))
            throw new DomainException("Password hash cannot be empty.");
        PasswordHash = newPasswordHash;
    }
}
```

**Why setters are private:** If `Username` had a public setter, *any* code anywhere could set it to an invalid value, bypassing every business rule. Private setters + factory methods/behavior methods (`Register`, `ChangePassword`) mean the entity can *never* exist in an invalid state.

**Entity lifecycle:** Created (via a factory method like `Register` or `Create`) → mutated over time only through its own methods → eventually deleted or archived. The entity, not outside code, controls every valid transition.

**Entity vs. database table:** A database table is a storage detail. An entity is a business concept. They often look similar (a `Post` table and a `Post` entity), but the entity can contain behavior (`post.Edit(...)`) that a table cannot, and the entity should never be shaped by database convenience (e.g., adding a column just because SQL needs it, without it representing a real concept).

## 6.4 Value Objects

**Formal definition:** An object defined entirely by its attributes/value, with no separate identity. Two value objects with the same values are considered equal.

**Simple explanation:** If two things "are the same" purely because their data is the same (not because they share an ID), it's a Value Object.

**Entity vs Value Object:**

| | Entity | Value Object |
|---|---|---|
| Identity | Has a unique ID | No ID — compared by value |
| Equality | `user1.Id == user2.Id` | `money1 == money2` if amount & currency match |
| Mutability | Can change over time | Usually immutable — create a new instance to "change" it |
| Example | `User`, `Post`, `Order` | `EmailAddress`, `Money`, `Address`, `Username` |

**C# example:**
```csharp
public sealed class EmailAddress
{
    public string Value { get; }

    public EmailAddress(string value)
    {
        if (string.IsNullOrWhiteSpace(value) || !value.Contains('@'))
            throw new DomainException("Invalid email address.");
        Value = value.Trim().ToLowerInvariant();
    }

    public override bool Equals(object? obj)
        => obj is EmailAddress other && Value == other.Value;

    public override int GetHashCode() => Value.GetHashCode();
}
```

Using `record` types in modern C# makes this even shorter, since records give you value equality for free:
```csharp
public sealed record Money(decimal Amount, string Currency)
{
    public Money
    {
        if (Amount < 0) throw new DomainException("Amount cannot be negative.");
    }
}
```

## 6.5 Enums

Enums belong in the Domain layer when they represent a genuine business concept with a fixed, small set of states.

```csharp
public enum PostVisibility
{
    Public,
    FollowersOnly,
    Private
}
```

Keep enums in Domain if the *business* defines the values. If the values are purely a technical/UI concern (e.g., a sort order for a dropdown), they don't belong in Domain.

## 6.6 Domain Services

**Definition:** A Domain Service holds business logic that doesn't naturally belong to a single entity because it involves *multiple* entities or a business concept that isn't itself a "thing."

**When to use:** When an operation needs two or more entities to compute a business rule, e.g., `TransferMoneyService` needing both a source and destination `Account`.

**When NOT to use:** If the logic naturally belongs to one entity, put it there instead. Domain Services are the exception, not the default — overusing them leads to an "anemic domain model" (Section 24).

**Domain Service vs Application Service:** A Domain Service contains pure business rules and has no knowledge of use cases, DTOs, or infrastructure. An Application Service (Use Case) orchestrates: it calls repositories, domain services, and entities together to fulfill one specific use case, and it *can* know about DTOs and infrastructure interfaces.

## 6.7 Domain Events

**Definition:** A Domain Event represents something significant that happened in the business, expressed in past tense.

**Why useful:** They decouple side effects from the core operation. `CreatePost` doesn't need to know about email notifications directly — it just raises `PostCreated`, and something else reacts.

**Examples:** `UserRegistered`, `PostCreated`, `OrderPlaced`.

```csharp
public sealed record PostCreated(Guid PostId, Guid AuthorId, DateTime OccurredAt) : IDomainEvent;
```

**Synchronous vs asynchronous handling (conceptual):**
- *Synchronous:* the event is handled immediately, in the same transaction/request (e.g., updating a denormalized counter).
- *Asynchronous:* the event is queued and handled later, possibly by a different process (e.g., sending an email, notifying followers). This keeps the original request fast and resilient — if the email service is down, post creation still succeeds.

## 6.8 Domain Exceptions

Business-rule violations should throw exceptions defined in the Domain layer, not generic `Exception` or infrastructure-specific exceptions.

```csharp
public class DomainException : Exception
{
    public DomainException(string message) : base(message) { }
}
```

These exceptions are caught higher up (typically in middleware, Section 19) and translated into proper HTTP responses. The Domain layer doesn't know or care about HTTP status codes — that's a Presentation concern.

## 6.9 Business Rules

**Definition:** A business rule is a constraint or policy that reflects how the real-world business actually works, independent of any technology.

**Examples from a Twitter-like app:**
- A user cannot like the same post twice.
- A user cannot follow themselves.
- A post cannot exceed 280 characters.
- Only the owner can delete a post.

**Where these rules live:** Inside the Domain layer — either on the relevant entity, or in a Domain Service when multiple entities are involved.

```csharp
public class Post
{
    public Guid AuthorId { get; private set; }

    public void EnsureCanBeDeletedBy(Guid requestingUserId)
    {
        if (requestingUserId != AuthorId)
            throw new DomainException("Only the owner can delete this post.");
    }
}
```

Putting this rule in the entity means it is enforced *everywhere* the entity is used — the API, a background job, an admin tool — because it's impossible to bypass without going through `Post` itself.

---

# 7. Application Layer

> **"The Application Layer defines what the system can do."**

The Application layer sits directly outside Domain. It doesn't contain business *rules* (those live in Domain) — it contains **orchestration**: coordinating entities, repositories, and services to fulfill a specific use case.

## 7.1 What Belongs Here

- Use Cases / Application Services
- Commands and Queries
- DTOs (request/response models for use cases)
- Repository interfaces (e.g., `IPostRepository`) — the interface, not the implementation
- Validators (rules about input shape, not business rules)
- Application-specific exceptions (e.g., `NotFoundException`, `ValidationException`)

## 7.2 What Does NOT Belong Here

- No EF Core / raw SQL (that's Infrastructure)
- No ASP.NET Core `HttpContext` or controller types (that's Presentation)
- No actual business rules baked into orchestration code (those belong in Domain entities)

## 7.3 Dependency Inversion in Practice

The Application layer defines *interfaces* for anything it needs from the outside world (`IPostRepository`, `IEmailSender`), but never implements them. Infrastructure provides the implementations. This is Dependency Inversion applied concretely (full treatment in Section 10).

## 7.4 Example Use Cases

```
CreatePost   DeletePost   LikePost   FollowUser   GetPost   GetUserProfile
```

Each of these becomes one Use Case class (Section 8) or one Command/Query handler (Section 9), depending on the style chosen.

---

# 8. Use Cases

**Definition:** A Use Case represents one specific thing a user (or system) can do — one entry point into the Application layer, with a clear input and output.

**Flow:**
```
Request
   ↓
Use Case
   ↓
Business Rules (Domain)
   ↓
Repository Interface
   ↓
Response
```

**Complete C# example — `CreatePostUseCase`:**

```csharp
// Application/Posts/Commands/CreatePost/CreatePostRequest.cs
public record CreatePostRequest(Guid AuthorId, string Content);

// Application/Posts/Commands/CreatePost/CreatePostResponse.cs
public record CreatePostResponse(Guid Id, string Content, DateTime CreatedAt);

// Application/Interfaces/IPostRepository.cs
public interface IPostRepository
{
    Task AddAsync(Post post, CancellationToken ct);
    Task<Post?> GetByIdAsync(Guid id, CancellationToken ct);
}

// Application/Posts/Commands/CreatePost/CreatePostUseCase.cs
public class CreatePostUseCase
{
    private readonly IPostRepository _postRepository;

    public CreatePostUseCase(IPostRepository postRepository)
    {
        _postRepository = postRepository;
    }

    public async Task<CreatePostResponse> ExecuteAsync(CreatePostRequest request, CancellationToken ct)
    {
        // 1. Call domain logic — the entity enforces its own rules
        var post = Post.Create(request.AuthorId, request.Content);

        // 2. Persist via the repository abstraction
        await _postRepository.AddAsync(post, ct);

        // 3. Map to output model
        return new CreatePostResponse(post.Id, post.Content, post.CreatedAt);
    }
}
```

**Breaking it down:**
- **Input model** (`CreatePostRequest`) — a plain, framework-agnostic input.
- **Validation** — basic shape validation (e.g., "AuthorId is not empty") can happen here or in a dedicated validator (Section 25); *business* validation (e.g., "content ≤ 280 chars") is delegated to the Domain entity.
- **Calling domain logic** — `Post.Create(...)` is where the actual business rule lives.
- **Repository interaction** — the use case only knows the *interface*, `IPostRepository`, never the concrete EF Core implementation.
- **Output model** (`CreatePostResponse`) — a DTO shaped for the caller, not the raw entity.

**Why Use Cases beat business logic in Controllers:**
- Reusable from anywhere — an API controller, a background job, a test, a CLI — without duplicating logic.
- Trivially unit-testable: swap `IPostRepository` for a fake, no ASP.NET Core or database needed.
- Keeps controllers thin and focused purely on HTTP translation.
- Each use case has one clear name and one clear job — easy to find, easy to reason about.

---

# 9. Commands and Queries

## 9.1 Command
A **Command** changes state. It represents an intent to *do* something.

```
CreatePost   DeletePost   LikePost   FollowUser
```

## 9.2 Query
A **Query** reads data. It never changes state.

```
GetPost   GetUser   GetFeed   GetComments
```

## 9.3 CQRS (Command Query Responsibility Segregation) — Conceptually

CQRS takes the Command/Query distinction further: it separates the *models* used for writing from the models used for reading — sometimes even using entirely different data stores for each.

> **Clean Architecture does NOT require CQRS.**

They are independent ideas that happen to combine well. You can build a fully correct Clean Architecture application using simple, symmetric "Use Case" classes for both reads and writes, with no CQRS at all.

**When CQRS is useful:**
- Read and write workloads have very different performance needs (e.g., a feed read millions of times per day vs. a post created occasionally).
- Read models benefit from being flattened/denormalized differently than the write model needs to be structured for consistency.
- The team is comfortable with the added complexity (separate models, possibly separate data paths, and eventual consistency between them).

**When it may be unnecessary:**
- Small-to-medium applications where a single model serves both reads and writes just fine.
- Early-stage projects where the added abstraction slows the team down for no real benefit yet (see Section 24, Overengineering).

A lightweight middle ground many teams use: keep simple, separate `Command` and `Query` classes/handlers (often via MediatR, Section 32) without going all the way to separate read/write data stores.

---

# 10. DTOs (Data Transfer Objects)

**Definition:** A DTO is a plain object used to move data across a boundary (e.g., from the API to the client), containing no behavior — just data.

**Why needed:** Entities are shaped for enforcing business rules; DTOs are shaped for what a specific caller needs to send or receive. These are often different shapes.

**Entity vs DTO:**

| | Entity | DTO |
|---|---|---|
| Purpose | Enforce business rules | Move data across a boundary |
| Behavior | Has methods | Pure data, no behavior |
| Location | Domain | Application/Presentation |
| Fields | Everything needed for business logic | Only what the specific request/response needs |

**Request DTO / Response DTO:**
```csharp
public record CreatePostRequest(string Content);
public record PostResponse(Guid Id, string Content, string AuthorUsername, DateTime CreatedAt);
public record UserResponse(Guid Id, string Username);
```

**Mapping:** Converting between entities and DTOs, typically in the Application layer (inside a Use Case) or via a small mapping utility. Can be done by hand or with a library like AutoMapper — hand-written mapping is often clearer for small projects.

**Why entities should not always be returned directly from the API:**
- **Security** — an entity might carry a `PasswordHash` field that must never reach a client.
- **API contract stability** — if you return the entity directly, every internal refactor (renaming a field, adding a navigation property) becomes a breaking change for every API consumer. A DTO is a deliberate, stable contract.
- **Avoiding serialization issues** — entities often have circular navigation properties (`Post.Author.Posts.Author...`) that break JSON serialization; DTOs avoid this entirely.

---

# 11. Repository Pattern

## 11.1 The Problem

```
Application → EF Core directly
```

If Use Cases call `DbContext` directly, the Application layer becomes coupled to EF Core, which violates the Dependency Rule (Application should not depend on Infrastructure details).

## 11.2 The Clean Architecture Approach

```
Application
    ↓
IPostRepository
    ↑
PostRepository
    ↓
EF Core
    ↓
PostgreSQL
```

**What is a Repository?** An abstraction that represents a collection of domain objects, hiding *how* they're actually stored and retrieved.

**Why interfaces are defined inward:** `IPostRepository` lives in the Application (or Domain) layer because that's *who needs it* — Application needs to fetch and save posts. It doesn't need to know or care how that's technically done.

**Why implementations belong to Infrastructure:** The actual `PostRepository` class knows about EF Core and PostgreSQL — technical details that must stay outside the core.

**Repository responsibilities:**
- Fetching entities by identity or simple criteria
- Adding, updating, and removing entities
- Translating between the persistence model and the domain entity (when they differ)

**What should NOT go inside repositories:**
- Business rules (those belong in the Domain entity)
- HTTP-related logic
- Complex orchestration across multiple aggregates (that belongs in a Use Case or Domain Service)

**Complete C# example:**

```csharp
// Application/Interfaces/IPostRepository.cs
public interface IPostRepository
{
    Task<Post?> GetByIdAsync(Guid id, CancellationToken ct);
    Task AddAsync(Post post, CancellationToken ct);
    Task DeleteAsync(Post post, CancellationToken ct);
}

// Infrastructure/Repositories/PostRepository.cs
public class PostRepository : IPostRepository
{
    private readonly ApplicationDbContext _dbContext;

    public PostRepository(ApplicationDbContext dbContext) => _dbContext = dbContext;

    public async Task<Post?> GetByIdAsync(Guid id, CancellationToken ct)
        => await _dbContext.Posts.FirstOrDefaultAsync(p => p.Id == id, ct);

    public async Task AddAsync(Post post, CancellationToken ct)
    {
        await _dbContext.Posts.AddAsync(post, ct);
        await _dbContext.SaveChangesAsync(ct);
    }

    public async Task DeleteAsync(Post post, CancellationToken ct)
    {
        _dbContext.Posts.Remove(post);
        await _dbContext.SaveChangesAsync(ct);
    }
}
```

---

# 12. Unit of Work

**Definition:** The Unit of Work pattern tracks a set of changes across possibly multiple repositories and commits them together as one atomic transaction.

**Why it exists:** If a single use case needs to change a `Post` *and* a `User` (e.g., "delete post and decrement the user's post count"), you want both changes to succeed or fail together.

**Relationship with EF Core `DbContext`:** In EF Core, `DbContext` **already implements the Unit of Work pattern**. Every `DbSet` you touch is tracked, and a single `SaveChangesAsync()` call commits all changes together in one transaction. This is one of the most commonly misunderstood points in Clean Architecture discussions.

**When a separate Unit of Work abstraction is useful:**
- When you genuinely need to swap persistence technology (rare, and often theoretical for most teams).
- When you want a single, explicit "commit point" abstraction shared across several repositories in tests.

**When it becomes unnecessary abstraction:**
- If your project uses EF Core and always will, wrapping `DbContext` in another `IUnitOfWork` interface often just adds an extra layer with no real benefit — `DbContext` already gives you this for free.

> Do not treat Unit of Work as mandatory. Many well-designed Clean Architecture ASP.NET Core + EF Core projects skip a separate Unit of Work interface entirely and rely on `SaveChangesAsync()`.

---

# 13. Infrastructure Layer

> **"Infrastructure contains implementation details."**

## 13.1 What Belongs Here

- Entity Framework Core `DbContext` and entity configurations
- PostgreSQL-specific code
- Repository implementations (`PostRepository : IPostRepository`)
- External API clients (payment gateways, third-party services)
- Email sending implementations
- File storage implementations (e.g., S3-compatible storage)
- Redis / caching implementations
- Authentication infrastructure (JWT token generation, password hashers)
- Logging provider configuration (Serilog, etc.)

## 13.2 What Does NOT Belong Here

- Business rules
- Orchestration logic that belongs in a Use Case
- Anything the Application layer should own as an interface — Infrastructure only *implements* interfaces defined inward, it doesn't invent new business concepts

## 13.3 Example — JWT Token Generator

```csharp
// Application/Interfaces/ITokenGenerator.cs  (interface lives in Application)
public interface ITokenGenerator
{
    string GenerateToken(User user);
}

// Infrastructure/Auth/JwtTokenGenerator.cs (implementation lives in Infrastructure)
public class JwtTokenGenerator : ITokenGenerator
{
    private readonly JwtSettings _settings;

    public JwtTokenGenerator(IOptions<JwtSettings> settings) => _settings = settings.Value;

    public string GenerateToken(User user)
    {
        var claims = new[] { new Claim("sub", user.Id.ToString()), new Claim("username", user.Username) };
        var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_settings.Secret));
        var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256);
        var token = new JwtSecurityToken(_settings.Issuer, _settings.Audience, claims,
            expires: DateTime.UtcNow.AddHours(2), signingCredentials: creds);
        return new JwtSecurityTokenHandler().WriteToken(token);
    }
}
```

Notice: the Application layer only ever sees `ITokenGenerator`. It has no idea JWT is even being used — it could be swapped for session tokens without any Application code changing.

---

# 14. Entity Framework Core Integration

A realistic Infrastructure setup for ASP.NET Core + EF Core + PostgreSQL:

```
Infrastructure
│
├── Persistence
│   ├── ApplicationDbContext.cs
│   ├── Configurations
│   │   ├── PostConfiguration.cs
│   │   └── UserConfiguration.cs
│   └── Migrations
│
└── Repositories
    ├── PostRepository.cs
    └── UserRepository.cs
```

```csharp
// Infrastructure/Persistence/ApplicationDbContext.cs
public class ApplicationDbContext : DbContext
{
    public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options) { }

    public DbSet<Post> Posts => Set<Post>();
    public DbSet<User> Users => Set<User>();

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.ApplyConfigurationsFromAssembly(typeof(ApplicationDbContext).Assembly);
    }
}
```

**Why EF Core should generally not leak into Domain:** If `Post` inherits from an EF Core base class, uses `[Table]`/`[Column]` attributes, or has public parameterless constructors purely to satisfy EF Core, the Domain layer becomes coupled to a specific ORM. Using `IEntityTypeConfiguration<T>` (Section 15) instead of attributes keeps EF Core's concerns entirely in Infrastructure, letting Domain stay pure. (A private parameterless constructor for EF Core materialization, as shown in Section 6.3, is a small, commonly accepted pragmatic exception — it doesn't leak EF Core *types* into Domain, just accommodates how ORMs instantiate objects.)

---

# 15. Entity Configuration

**Why configuration is separated from entities:** Keeping mapping details (table names, column constraints, relationships) in dedicated configuration classes — rather than attributes directly on the entity — keeps the Domain entity free of persistence concerns.

```csharp
// Infrastructure/Persistence/Configurations/PostConfiguration.cs
public class PostConfiguration : IEntityTypeConfiguration<Post>
{
    public void Configure(EntityTypeBuilder<Post> builder)
    {
        builder.ToTable("Posts");

        builder.HasKey(p => p.Id);

        builder.Property(p => p.Content)
            .IsRequired()
            .HasMaxLength(Post.MaxContentLength);

        builder.HasOne<User>()
            .WithMany()
            .HasForeignKey(p => p.AuthorId)
            .OnDelete(DeleteBehavior.Cascade);

        builder.HasIndex(p => p.AuthorId);
    }
}
```

Covers: **primary keys** (`HasKey`), **relationships** (`HasOne`/`WithMany`), **constraints** (`IsRequired`), **indexes** (`HasIndex`), **required fields**, and **max lengths** — all PostgreSQL/EF-specific concerns that belong entirely in Infrastructure.

---

# 16. Presentation Layer / API Layer

## 16.1 What Belongs Here

Controllers, routing, model binding, authentication/authorization wiring, middleware, exception-handling middleware, request/response translation.

## 16.2 Controllers Should Be Thin

**Bad controller:**
```
Controller
 ├── Validation
 ├── Business logic
 ├── Database queries
 ├── Email
 └── Notifications
```

**Good controller:**
```
Controller
     ↓
Use Case
     ↓
Domain
```

```csharp
[ApiController]
[Route("api/posts")]
public class PostsController : ControllerBase
{
    private readonly CreatePostUseCase _createPost;

    public PostsController(CreatePostUseCase createPost) => _createPost = createPost;

    [HttpPost]
    [Authorize]
    public async Task<ActionResult<CreatePostResponse>> Create(
        [FromBody] CreatePostRequestBody body, CancellationToken ct)
    {
        var authorId = Guid.Parse(User.FindFirstValue("sub")!);
        var response = await _createPost.ExecuteAsync(new CreatePostRequest(authorId, body.Content), ct);
        return CreatedAtAction(nameof(GetById), new { id = response.Id }, response);
    }

    [HttpGet("{id:guid}")]
    public async Task<ActionResult<PostResponse>> GetById(Guid id, CancellationToken ct)
        => Ok(await _getPost.ExecuteAsync(id, ct));
}
```

The controller's *only* job: read the HTTP request, call a use case, translate the result into an HTTP response. It has no idea how a post is validated, stored, or what database is used.

---

# 17. Dependency Injection

**What "dependency" means:** If class `A` needs class `B` to do its job, `A` depends on `B`.

**What Dependency Injection (DI) means:** Instead of a class creating its own dependencies (`new PostRepository()`), the dependencies are *given* to it from the outside — usually through the constructor.

**Constructor injection:**
```csharp
public class CreatePostUseCase
{
    private readonly IPostRepository _postRepository;
    public CreatePostUseCase(IPostRepository postRepository) => _postRepository = postRepository;
}
```
`CreatePostUseCase` never decides *which* `IPostRepository` implementation it gets — ASP.NET Core's DI container decides that at startup.

**Service registration:**
```csharp
builder.Services.AddScoped<IPostRepository, PostRepository>();
builder.Services.AddScoped<CreatePostUseCase>();
builder.Services.AddDbContext<ApplicationDbContext>(options =>
    options.UseNpgsql(builder.Configuration.GetConnectionString("Default")));
```

**Service lifetimes:**

| Lifetime | New instance created | Typical use |
|---|---|---|
| **Transient** | Every time it's requested | Lightweight, stateless services |
| **Scoped** | Once per HTTP request | `DbContext`, repositories (share one transaction per request) |
| **Singleton** | Once for the app's lifetime | Configuration, caches, stateless utilities |

**Why this matters for Clean Architecture:** DI is the mechanism that *implements* Dependency Inversion at runtime. Without a DI container, you'd still have interfaces, but you'd need to manually wire up every implementation everywhere — DI automates that wiring at the application's single "composition root" (typically `Program.cs`), keeping every other layer blissfully unaware of concrete types.

---

# 18. Dependency Inversion Principle (DIP)

This is one of the most important — and most tested-in-interviews — concepts in Clean Architecture, so it deserves a deep, dedicated look.

**Formal definition:**
1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
2. Abstractions should not depend on details. Details should depend on abstractions.

**Simple explanation:** Business logic (high-level) shouldn't be "wired directly" to technical details (low-level) like a specific database. Instead, both sides should agree on a shared interface, and the technical detail is the one that has to conform to it.

**Bad:**
```
Application
     ↓
PostgreSQL Repository
```
Application directly `new`s up or references a `PostgresPostRepository` class. If PostgreSQL is replaced, Application code must change.

**Good:**
```
Application
     ↓
IPostRepository
     ↑
PostgreSQL Repository
```
Application only depends on `IPostRepository`. `PostgresPostRepository` depends on (implements) that same interface. The arrow of *implementation* flows from Infrastructure into Application's interface, but the arrow of *source-code dependency* still flows from Infrastructure inward — Infrastructure knows about Application's interface, but Application knows nothing about Infrastructure.

**Why the interface is owned by the inner layer:** The inner layer (Application) defines *what it needs* ("I need a way to get a post by ID"). The outer layer (Infrastructure) is responsible for *how* that need gets fulfilled. Ownership follows need, not implementation.

**Simple analogy:** A restaurant's menu (interface) is written by the restaurant (business/inner layer): "We serve a Margherita pizza." The kitchen (infrastructure) can change its supplier, its oven, even its chef — as long as it keeps producing what the menu promises. The menu never changes to match the kitchen's internal equipment.

---

# 19. Complete Project Structure

```
TwitterClone.sln

src/
│
├── TwitterClone.Domain/
│   ├── Entities/
│   ├── ValueObjects/
│   ├── Enums/
│   ├── Events/
│   ├── Exceptions/
│   └── Services/
│
├── TwitterClone.Application/
│   ├── Posts/
│   │   ├── Commands/
│   │   ├── Queries/
│   │   ├── DTOs/
│   │   └── Validators/
│   ├── Users/
│   │   ├── Commands/
│   │   ├── Queries/
│   │   └── DTOs/
│   └── Interfaces/
│       ├── IPostRepository.cs
│       ├── IUserRepository.cs
│       ├── ITokenGenerator.cs
│       └── IEmailSender.cs
│
├── TwitterClone.Infrastructure/
│   ├── Persistence/
│   │   ├── ApplicationDbContext.cs
│   │   ├── Configurations/
│   │   └── Migrations/
│   ├── Repositories/
│   ├── Auth/
│   └── Email/
│
└── TwitterClone.API/
    ├── Controllers/
    ├── Middleware/
    └── Program.cs

tests/
│
├── TwitterClone.UnitTests/
└── TwitterClone.IntegrationTests/
```

**Why each folder exists:**
- `Domain/Entities` — the core business objects.
- `Domain/ValueObjects` — small immutable concepts (email, money).
- `Domain/Events` — things that happened, for decoupled side effects.
- `Domain/Exceptions` — business-rule violation signals.
- `Application/{Feature}/Commands` and `/Queries` — grouped by feature (Posts, Users) rather than by technical type, so everything about "Posts" is easy to find together.
- `Application/Interfaces` — the abstractions Infrastructure must implement.
- `Infrastructure/Persistence` — everything EF Core and PostgreSQL specific.
- `API/Controllers` — thin HTTP entry points.

---

# 20. Project-to-Project Dependencies

```
Domain
  ↑
Application
  ↑
Infrastructure
  ↑
API
```

The API project typically references **both** Application (to call use cases) and Infrastructure (to register concrete implementations with DI at startup — the "composition root").

| Project | Can Reference |
|---|---|
| Domain | Nothing (only the .NET Base Class Library) |
| Application | Domain |
| Infrastructure | Application, Domain |
| API | Application, Infrastructure |

**Why Domain has zero dependency on infrastructure/framework concerns:** Domain is the most stable, most valuable, longest-lived part of the codebase — the actual business rules. Every dependency it *doesn't* have is a dependency that can never break it, never force it to change for the wrong reasons, and never prevent it from being reused (e.g., in a completely different type of application built around the same business).

---

# 21. Complete End-to-End Example — Twitter Clone

## 21.1 Features

Register, Login, Create Post, Delete Post, Like Post, Unlike Post, Follow User, Unfollow User, View Profile, View Feed, Add Comment.

## 21.2 Full Flow for "Create Post"

```
Next.js
   ↓
HTTP POST /api/posts
   ↓
API Controller (PostsController)
   ↓
Application Use Case (CreatePostUseCase)
   ↓
Domain Entity / Rules (Post.Create)
   ↓
Repository Interface (IPostRepository)
   ↓
Infrastructure Repository (PostRepository)
   ↓
EF Core (ApplicationDbContext)
   ↓
PostgreSQL
```

Each arrow is a real project boundary. The controller never imports EF Core. The use case never imports ASP.NET Core. The domain entity never imports either.

---

# 22. Complete Code Example — Create Post, End to End

**Domain — `Post.cs`:**
```csharp
namespace TwitterClone.Domain.Entities;

public class Post
{
    public const int MaxContentLength = 280;

    public Guid Id { get; private set; }
    public Guid AuthorId { get; private set; }
    public string Content { get; private set; } = string.Empty;
    public DateTime CreatedAt { get; private set; }

    private Post() { } // EF Core materialization only

    public static Post Create(Guid authorId, string content)
    {
        if (string.IsNullOrWhiteSpace(content))
            throw new DomainException("Content cannot be empty.");
        if (content.Length > MaxContentLength)
            throw new DomainException($"Content cannot exceed {MaxContentLength} characters.");

        return new Post
        {
            Id = Guid.NewGuid(),
            AuthorId = authorId,
            Content = content,
            CreatedAt = DateTime.UtcNow
        };
    }
}
```

**Application — DTOs, interface, and use case:**
```csharp
namespace TwitterClone.Application.Posts.Commands.CreatePost;

public record CreatePostRequest(Guid AuthorId, string Content);
public record CreatePostResponse(Guid Id, string Content, DateTime CreatedAt);

public class CreatePostUseCase
{
    private readonly IPostRepository _postRepository;
    public CreatePostUseCase(IPostRepository postRepository) => _postRepository = postRepository;

    public async Task<CreatePostResponse> ExecuteAsync(CreatePostRequest request, CancellationToken ct)
    {
        var post = Post.Create(request.AuthorId, request.Content);
        await _postRepository.AddAsync(post, ct);
        return new CreatePostResponse(post.Id, post.Content, post.CreatedAt);
    }
}
```

```csharp
namespace TwitterClone.Application.Interfaces;

public interface IPostRepository
{
    Task<Post?> GetByIdAsync(Guid id, CancellationToken ct);
    Task AddAsync(Post post, CancellationToken ct);
}
```

**Infrastructure — DbContext, configuration, repository:**
```csharp
namespace TwitterClone.Infrastructure.Persistence;

public class ApplicationDbContext : DbContext
{
    public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options) : base(options) { }
    public DbSet<Post> Posts => Set<Post>();

    protected override void OnModelCreating(ModelBuilder modelBuilder)
        => modelBuilder.ApplyConfigurationsFromAssembly(typeof(ApplicationDbContext).Assembly);
}

public class PostConfiguration : IEntityTypeConfiguration<Post>
{
    public void Configure(EntityTypeBuilder<Post> builder)
    {
        builder.ToTable("Posts");
        builder.HasKey(p => p.Id);
        builder.Property(p => p.Content).IsRequired().HasMaxLength(Post.MaxContentLength);
    }
}
```

```csharp
namespace TwitterClone.Infrastructure.Repositories;

public class PostRepository : IPostRepository
{
    private readonly ApplicationDbContext _db;
    public PostRepository(ApplicationDbContext db) => _db = db;

    public Task<Post?> GetByIdAsync(Guid id, CancellationToken ct)
        => _db.Posts.FirstOrDefaultAsync(p => p.Id == id, ct);

    public async Task AddAsync(Post post, CancellationToken ct)
    {
        await _db.Posts.AddAsync(post, ct);
        await _db.SaveChangesAsync(ct);
    }
}
```

**Presentation — Controller:**
```csharp
namespace TwitterClone.API.Controllers;

[ApiController]
[Route("api/posts")]
public class PostsController : ControllerBase
{
    private readonly CreatePostUseCase _createPost;
    public PostsController(CreatePostUseCase createPost) => _createPost = createPost;

    public record CreatePostBody(string Content);

    [HttpPost, Authorize]
    public async Task<ActionResult<CreatePostResponse>> Create(CreatePostBody body, CancellationToken ct)
    {
        var authorId = Guid.Parse(User.FindFirstValue("sub")!);
        var result = await _createPost.ExecuteAsync(new CreatePostRequest(authorId, body.Content), ct);
        return Ok(result);
    }
}
```

**Dependency Injection — `Program.cs`:**
```csharp
var builder = WebApplication.CreateBuilder(args);

builder.Services.AddDbContext<ApplicationDbContext>(o =>
    o.UseNpgsql(builder.Configuration.GetConnectionString("Default")));

builder.Services.AddScoped<IPostRepository, PostRepository>();
builder.Services.AddScoped<CreatePostUseCase>();

builder.Services.AddControllers();
var app = builder.Build();
app.MapControllers();
app.Run();
```

Every important part above stays on its own side of the Dependency Rule: `Post` never imports EF Core; `CreatePostUseCase` never imports ASP.NET Core; `PostsController` never imports Npgsql directly.

---

# 23. Clean Architecture + Next.js

```
Next.js
    ↓
HTTP/REST API
    ↓
ASP.NET Core
    ↓
Clean Architecture
    ↓
PostgreSQL
```

- **The frontend never touches PostgreSQL directly** — it only ever talks HTTP to the ASP.NET Core API.
- **Authentication token flow:** Next.js sends login credentials → API validates and returns a JWT → Next.js stores the token (e.g., in an httpOnly cookie or memory) → subsequent requests include `Authorization: Bearer <token>`.
- **Request/response DTOs** are the actual contract between frontend and backend — this is exactly the same DTO concept from Section 10, just consumed by a different technology.
- **API contracts** should be stable and versionable; Next.js and ASP.NET Core evolve independently as long as the contract holds.
- **CORS**, conceptually, is the browser-enforced rule that a page served from one origin (e.g., `localhost:3000`) cannot call an API on a different origin (e.g., `localhost:5000`) unless the API explicitly allows it. ASP.NET Core configures this via `AddCors`.
- **Error responses** should follow a consistent shape (Section 26) so the frontend can handle failures predictably regardless of which use case failed.

---

# 24. Authentication and Authorization

**Authentication** = "Who are you?" (verifying identity).
**Authorization** = "What are you allowed to do?" (verifying permission).

| Component | Layer | Why |
|---|---|---|
| Password hashing algorithm | Infrastructure | Technical implementation detail |
| JWT generation/validation | Infrastructure | Framework/library-specific |
| "A user must be authenticated to create a post" | Application/Presentation (`[Authorize]`) | Cross-cutting policy, not a core business rule about `Post` itself |
| "Only the owner can delete a post" | Domain | A genuine business rule about the `Post` entity |
| ASP.NET Core Identity setup | Infrastructure | Framework-specific |
| Claims, Roles, Policies | Infrastructure/Presentation | Framework mechanisms for expressing authorization |

**Clean structure:**
```
Application/Interfaces/IPasswordHasher.cs
Application/Interfaces/ITokenGenerator.cs
Infrastructure/Auth/BCryptPasswordHasher.cs
Infrastructure/Auth/JwtTokenGenerator.cs
API/Program.cs   (registers JWT middleware, [Authorize] attributes)
```

**The key distinction:** "You must be logged in" is largely an *application-level policy*, often expressed through Presentation-layer attributes like `[Authorize]`. "Only the post's owner may delete it" is a genuine *domain rule* that belongs on the `Post` entity itself (`EnsureCanBeDeletedBy`, shown in Section 6.9) — because that rule is true regardless of whether the request came from HTTP, a background job, or a test.

---

# 25. Validation

## 25.1 Input Validation
Concerned with the *shape* of data — is it present, is it the right length/format?

Example: "Content is required." / "Maximum 280 characters."

**Where it lives:** Typically at the edge — in the Application layer via a dedicated validator (or the Presentation layer via model binding attributes for very simple cases).

## 25.2 Business Validation
Concerned with whether an operation is *allowed* given the current state of the business.

Example: "A user cannot follow themselves."

**Where it lives:** The Domain layer, because it's a business rule, not a shape check.

## 25.3 FluentValidation (Conceptual)

FluentValidation is a popular .NET library for expressing input validation rules declaratively:

```csharp
public class CreatePostValidator : AbstractValidator<CreatePostRequestBody>
{
    public CreatePostValidator()
    {
        RuleFor(x => x.Content).NotEmpty().MaximumLength(Post.MaxContentLength);
    }
}
```

Validators like this typically live in the **Application layer**, close to the request/command they validate, and run *before* the use case executes — catching malformed input early, while leaving true business rules to the Domain entity.

---

# 26. Error Handling

| Error type | Typical HTTP status |
|---|---|
| Domain exception (business rule violated) | 400 Bad Request |
| Application validation error | 400 Bad Request |
| Not found | 404 Not Found |
| Unauthorized (not authenticated) | 401 Unauthorized |
| Forbidden (authenticated but not allowed) | 403 Forbidden |
| Conflict (e.g., duplicate) | 409 Conflict |
| Unhandled/unexpected error | 500 Internal Server Error |

**Centralized exception handling via middleware:**
```csharp
public class ExceptionHandlingMiddleware
{
    private readonly RequestDelegate _next;
    public ExceptionHandlingMiddleware(RequestDelegate next) => _next = next;

    public async Task InvokeAsync(HttpContext context)
    {
        try { await _next(context); }
        catch (DomainException ex)
        {
            context.Response.StatusCode = StatusCodes.Status400BadRequest;
            await context.Response.WriteAsJsonAsync(new { statusCode = 400, message = ex.Message });
        }
        catch (NotFoundException ex)
        {
            context.Response.StatusCode = StatusCodes.Status404NotFound;
            await context.Response.WriteAsJsonAsync(new { statusCode = 404, message = ex.Message });
        }
    }
}
```

Example error response:
```json
{
  "statusCode": 400,
  "message": "Post content cannot be empty"
}
```

Centralizing this means controllers never write repetitive `try/catch` blocks — they just let exceptions propagate, and the middleware translates Domain/Application exceptions into consistent HTTP responses.

---

# 27. Testing in Clean Architecture

Clean Architecture makes testing dramatically easier because business logic has **no infrastructure dependencies** to fake or spin up.

## 27.1 Unit Tests
Test Domain rules, Use Cases, and Validators — fast, no database, no HTTP server.

```csharp
[Fact]
public void Create_Post_Throws_When_Content_Too_Long()
{
    var longContent = new string('a', 281);
    Assert.Throws<DomainException>(() => Post.Create(Guid.NewGuid(), longContent));
}

[Fact]
public async Task CreatePostUseCase_Persists_Valid_Post()
{
    var fakeRepo = new Mock<IPostRepository>();
    var useCase = new CreatePostUseCase(fakeRepo.Object);

    var result = await useCase.ExecuteAsync(new CreatePostRequest(Guid.NewGuid(), "Hello world"), default);

    fakeRepo.Verify(r => r.AddAsync(It.IsAny<Post>(), default), Times.Once);
    Assert.Equal("Hello world", result.Content);
}
```

## 27.2 Integration Tests
Test the API, database, repositories, and EF Core together — using a real (often containerized/test) PostgreSQL instance.

## 27.3 End-to-End Tests (Conceptual)
Test the whole system as a black box, often driving the API the same way a real frontend (Next.js) would — verifying the full request/response contract.

**Why business logic shouldn't require a real database for every unit test:** A test suite with hundreds of business-rule tests that each spin up PostgreSQL would be slow (minutes instead of seconds), flaky (database state leaking between tests), and expensive to run in CI. Because `Post.Create` has zero infrastructure dependency, it can be tested in microseconds, thousands of times, with total isolation.

---

# 28. Common Anti-Patterns

| Anti-pattern | Why problematic | Better approach |
|---|---|---|
| **Fat Controllers** | Controllers absorb validation, business logic, and persistence, becoming untestable and unreadable | Delegate to Use Cases; keep controllers to HTTP translation only |
| **Fat Services** | One giant "God service" doing everything for an entire module | Split by use case/feature; one class, one responsibility |
| **Generic Repository Everywhere** | `IRepository<T>` for every entity hides intent and often leaks IQueryable, defeating the abstraction | Use specific repositories (`IPostRepository`) shaped around real use cases |
| **Overusing Interfaces** | An interface for every single class "just in case," even when there's only ever one implementation | Add an interface when there's a real reason (testing, swappability), not by default |
| **Anemic Domain Model** | Entities are just property bags with public setters; all logic lives in services | Put behavior on entities; let them enforce their own invariants |
| **Business Logic in Controllers** | Untestable without HTTP; duplicated across endpoints | Move to Use Cases and Domain entities |
| **Business Logic in Repositories** | Mixes persistence concerns with business rules; hard to reuse | Keep repositories to data access only; rules belong in Domain |
| **Domain Depending on EF Core** | Breaks the Dependency Rule; ties business rules to a specific ORM | Keep Domain framework-free; map via `IEntityTypeConfiguration` in Infrastructure |
| **Application Depending Directly on PostgreSQL** | Same as above — locks core logic to one database | Depend on repository interfaces, not `Npgsql`/EF directly |
| **Returning EF Entities Directly from API** | Leaks internal fields (e.g., password hashes), breaks API contract stability, causes serialization issues | Map to DTOs before returning |
| **Creating Too Many Layers for a Tiny Project** | A 3-endpoint hobby project with 4 projects, 15 interfaces, and a Unit of Work is slower to build and understand than it needs to be | Match architecture to project size and expected lifespan |
| **Overengineering** | Abstraction added "because Clean Architecture says so," without a concrete need | Add abstraction when it solves a real, current problem |

---

# 29. Clean Architecture vs Other Architectures

| Architecture | Core idea | Relationship to Clean Architecture |
|---|---|---|
| **Layered / N-Tier** | Presentation → Business → Data, stacked linearly | Clean Architecture is a stricter version — it enforces the Dependency Rule explicitly; plain layered architecture often allows Business → Data → back up, and doesn't insist on interfaces pointing inward |
| **3-Tier Architecture** | A specific, common case of layered architecture: Presentation, Business Logic, Data | Same relationship as above — Clean Architecture adds explicit dependency direction rules |
| **Onion Architecture** | Concentric circles with Domain at the center, all dependencies pointing inward | Essentially the direct predecessor of Clean Architecture — nearly identical philosophy (see Section 30) |
| **Hexagonal / Ports and Adapters** | The application core exposes "ports" (interfaces); external systems plug in via "adapters" | Conceptually equivalent to Clean Architecture's repository/interface pattern — "port" ≈ interface, "adapter" ≈ Infrastructure implementation |
| **Vertical Slice Architecture** | Organize by feature (all code for "Create Post" together) rather than by technical layer | Complementary, not opposed — can be combined with Clean Architecture's dependency rules (see Section 31) |
| **MVC** | A UI/Presentation pattern: Model, View, Controller | Not a competing whole-application architecture — MVC typically lives *inside* the Presentation layer of a Clean Architecture solution |
| **CQRS** | Separate read and write models | An optional pattern that can be layered on top of, but is not required by, Clean Architecture (Section 9.3) |

These styles share the same underlying goals — separation of concerns, testability, and controlling dependency direction — expressed with different vocabulary and different emphasis.

# 30. Clean Architecture vs Onion Architecture

They are closely related enough that people often use the terms interchangeably.

- **Dependency direction:** Identical — always inward.
- **Domain center:** Both put the core business model at the very center with zero outward dependencies.
- **Application layer:** Both have a layer that orchestrates use cases around the Domain.
- **Infrastructure:** Both treat it as an outer, replaceable detail.
- **Presentation:** Both treat it as another outer, replaceable detail.

**Why the confusion:** Robert C. Martin's Clean Architecture (2012) was heavily influenced by Jeffrey Palermo's earlier Onion Architecture (2008) and Alistair Cockburn's Hexagonal Architecture (2005). All three describe the same underlying idea — protect the core, invert dependencies on infrastructure — with slightly different diagrams and terminology. In casual industry conversation, "Clean Architecture" has become the umbrella term most people reach for.

# 31. Clean Architecture vs Vertical Slice Architecture

**Layer-based organization** (traditional Clean Architecture folder layout):
```
Controllers/
Services/
Repositories/
Entities/
```

**Feature-based organization** (Vertical Slice):
```
Posts/
 ├── Create/
 ├── Delete/
 └── Get/

Users/
 ├── Register/
 ├── Login/
 └── Profile/
```

**When each may be useful:**
- Layer-based grouping makes the *dependency rule* very visible — you can see at a glance which project can reference which.
- Feature-based grouping makes *day-to-day development* easier — everything about "Create Post" (request, handler, validator, response) sits in one folder instead of being scattered across four.

Many real-world projects combine both: Clean Architecture's *project-level* dependency rules (Domain/Application/Infrastructure/API) **plus** feature-based folders *within* the Application project (as shown in Section 19's structure: `Application/Posts/...`, `Application/Users/...`).

---

# 32. MediatR

> **MediatR is NOT Clean Architecture.**

MediatR is a .NET library implementing the mediator pattern — it lets you send a `Command` or `Query` object and have it routed to exactly one `Handler`, without the caller needing a direct reference to that handler.

```csharp
public record CreatePostCommand(Guid AuthorId, string Content) : IRequest<CreatePostResponse>;

public class CreatePostHandler : IRequestHandler<CreatePostCommand, CreatePostResponse>
{
    public Task<CreatePostResponse> Handle(CreatePostCommand request, CancellationToken ct) { /* ... */ }
}

// Controller:
var result = await _mediator.Send(new CreatePostCommand(authorId, content));
```

**Pipeline Behaviors** let you add cross-cutting concerns (logging, validation, transactions) around every handler without touching each one individually.

**Advantages:** Reduces controller constructor bloat (one `IMediator` instead of many use case classes injected); makes cross-cutting concerns easy via pipeline behaviors; encourages a consistent Command/Query shape.

**Disadvantages:** Adds an extra layer of indirection that can make code harder to navigate (you can't "go to definition" as directly); another third-party dependency; can be overkill for smaller projects.

MediatR is a popular *implementation choice* for the Application layer's Use Cases — not a requirement of Clean Architecture itself. Plain `CreatePostUseCase` classes (as shown throughout this book) achieve the exact same architectural goals without it.

---

# 33. Generic Repository Debate

**`IRepository<T>`:**
```csharp
public interface IRepository<T>
{
    Task<T?> GetByIdAsync(Guid id);
    Task AddAsync(T entity);
    Task<IEnumerable<T>> GetAllAsync();
    // ...
}
```

**vs. specific repositories:**
```csharp
public interface IPostRepository
{
    Task<Post?> GetByIdAsync(Guid id, CancellationToken ct);
    Task<IEnumerable<Post>> GetFeedForUserAsync(Guid userId, CancellationToken ct);
}
```

**Pros of generic repository:** Less boilerplate for very simple CRUD entities; consistent shape.

**Cons of generic repository:** Encourages a "lowest common denominator" interface that doesn't reflect real use cases (e.g., `GetFeedForUserAsync` doesn't fit generically); often ends up exposing `IQueryable<T>` to escape its own limitations, which defeats the abstraction entirely by leaking EF Core query capability into the Application layer.

**Important nuance:** EF Core's `DbSet<T>` and `DbContext` **already behave like a generic repository and Unit of Work.** Wrapping them in your own `IRepository<T>` often just adds a redundant layer with no additional benefit — you're abstracting an abstraction.

**When abstraction is useful:** When you need to swap or fake the data source in tests, or genuinely might change the underlying technology. **When it's unnecessary:** When the "abstraction" simply mirrors `DbSet<T>` one-for-one and will only ever have one real implementation.

---

# 34. Overengineering

Clean Architecture is not about creating 100 interfaces, 100 services, and 100 abstractions for every small operation.

**Good abstraction:** Solves a real, present problem — e.g., `IPostRepository` lets you unit test `CreatePostUseCase` without a database.

**Abstraction for the sake of abstraction:** An interface with exactly one implementation, that will only ever have one implementation, added only because "that's what Clean Architecture does" — e.g., wrapping `DateTime.UtcNow` behind five layers of indirection for a script that runs once a year.

**Rule of thumb:** Add a layer or interface when it removes a real, current pain (untestable code, tangled dependencies) — not preemptively, "just in case." A 3-endpoint hobby project probably doesn't need a full four-project solution; a growing production system almost certainly benefits from one.

---

# 35. Real-World Industry Perspective

Real teams operate at a scale beyond a single API project. Some recurring concepts:

- **Monolith** — one deployable application containing everything.
- **Modular monolith** — one deployable application, but internally split into clearly bounded modules (e.g., Posts, Users, Notifications), each potentially structured with its own Clean Architecture layers.
- **Microservices** — multiple independently deployable services, each with its own database and lifecycle.
- **Shared libraries** — common code (e.g., a shared `Result<T>` type or logging setup) extracted into a NuGet package used across services.
- **Multiple teams** — architecture boundaries often mirror team boundaries (Conway's Law) — a team owns a module or service end-to-end.
- **CI/CD** — automated pipelines that build, test, and deploy on every change.
- **Docker** — packaging the API (and often PostgreSQL, for local dev) into containers for consistent environments.
- **Logging & Monitoring** — structured logging (e.g., Serilog) and observability tools (e.g., OpenTelemetry) — Infrastructure-layer concerns.
- **Configuration & Secrets** — environment-specific settings and credentials, typically injected via environment variables or a secrets manager, read through `IConfiguration` — never hardcoded into Domain or Application code.
- **Cloud services** — managed databases, storage, and messaging queues — all Infrastructure-layer details behind interfaces.

> **Clean Architecture is an internal application architecture, not a deployment architecture.**

This distinction matters: Clean Architecture describes how code *inside one application* is organized. Whether that application is deployed as a monolith, inside a modular monolith, or as one of many microservices is a completely separate decision.

# 36. Clean Architecture + Microservices

```
User Service        Post Service        Notification Service
     │                    │                        │
 (own DB)             (own DB)                 (own DB)
```

Each service can have its own internal Domain/Application/Infrastructure/API layers.

> Microservices ≠ Clean Architecture
> Clean Architecture ≠ Microservices

A single monolithic application can be beautifully Clean-Architected. A microservice can be internally a complete mess (a "fat controller" per service). The two ideas operate at different levels: microservices is about *how many deployable units* you have and how they communicate; Clean Architecture is about *how code within one of those units* is organized.

---

# 37. Practical Development Workflow

Using the Twitter Clone as the running example:

1. **Understand the requirement** — "Users should be able to create posts up to 280 characters."
2. **Identify domain concepts** — `Post`, `User`.
3. **Identify entities** — `Post` needs identity (`Id`), so it's an entity.
4. **Identify business rules** — content required, ≤280 characters, only the owner can delete.
5. **Identify use cases** — `CreatePost`, `DeletePost`, `GetPost`.
6. **Create Application interfaces** — `IPostRepository`.
7. **Implement Infrastructure** — `PostRepository`, `PostConfiguration`, EF Core migration.
8. **Create API endpoints** — `PostsController`.
9. **Add DI** — register everything in `Program.cs`.
10. **Add validation** — request-shape validation for `CreatePostRequestBody`.
11. **Add tests** — unit tests for `Post.Create` and `CreatePostUseCase`; integration test for the full endpoint.
12. **Integrate frontend** — Next.js calls `POST /api/posts` and renders the response.

This order matters: business understanding drives the Domain layer first, and technical details (Infrastructure, API wiring) come last — the exact opposite of the "controller-first, database-first" habit many beginners start with.

---

# 38. How to Decide Where Code Belongs

| Code | Layer |
|---|---|
| User Entity | Domain |
| Business Rule (e.g., "post ≤ 280 chars") | Domain |
| CreatePost Use Case | Application |
| DTO | Application |
| Repository Interface | Application |
| EF Core Repository implementation | Infrastructure |
| DbContext | Infrastructure |
| PostgreSQL Configuration | Infrastructure |
| Controller | API (Presentation) |
| Middleware | API (Presentation) |
| JWT implementation | Infrastructure (token generation logic) / API (middleware wiring) |
| HTTP request model | API or Application, depending on design — if it's identical to the use case's input, it can live in Application; if it's HTTP-specific (e.g., includes route/query binding attributes), keep it in API and map to an Application DTO |

**Reasoning behind the harder cases:**
- **JWT** — *generating and validating* a token is a technical implementation detail (Infrastructure). *Wiring up* `[Authorize]` and the authentication middleware pipeline is Presentation, since it's about how HTTP requests are processed.
- **HTTP request model** — the deciding question is: "Does this shape exist purely because of HTTP (route parameters, form binding), or does it represent what the use case actually needs?" If it's the latter, it can be the same object used in Application; if the former, keep a thin API-only model and map it.

---

# 39. Interview Questions

1. **What is Clean Architecture?** A way of organizing code into concentric layers where all dependencies point inward toward business logic, keeping frameworks, databases, and UI as replaceable outer details.
2. **What problem does it solve?** Tight coupling between business logic and technical details, which makes systems hard to test, maintain, and evolve.
3. **What is the Dependency Rule?** Source-code dependencies can only point inward; nothing inner can know about anything outer.
4. **What is Dependency Inversion?** High-level and low-level modules both depend on abstractions, instead of the high-level module depending directly on the low-level one.
5. **Why should Domain not depend on Infrastructure?** So business rules stay stable, portable, and testable regardless of which database or framework is used.
6. **What belongs in Domain?** Entities, value objects, domain services, domain events, domain exceptions, and business rules.
7. **What belongs in Application?** Use cases, DTOs, repository interfaces, and orchestration logic.
8. **What is a Repository?** An abstraction representing a collection of domain objects, hiding how they're actually stored.
9. **Why use interfaces?** They let inner layers depend on abstractions instead of concrete outer-layer implementations, enabling testability and swappability.
10. **What is a DTO?** A plain object used to move data across a boundary, with no behavior.
11. **Entity vs DTO?** An entity enforces business rules and has identity; a DTO is a shape for transferring data, with neither identity nor behavior.
12. **What is a Use Case?** A class representing one specific thing the system can do, with a clear input and output.
13. **What is CQRS?** A pattern separating read (query) models from write (command) models.
14. **Is CQRS required?** No — Clean Architecture doesn't require it; it's an optional, separate pattern.
15. **Is MediatR required?** No — it's a popular library for implementing the Application layer, not a requirement of the architecture itself.
16. **Is Repository Pattern required?** Not strictly, but it's the standard way to satisfy Dependency Inversion for data access; some teams use EF Core directly behind their own thin abstraction instead.
17. **What is Unit of Work?** A pattern that commits multiple changes as one atomic transaction; EF Core's `DbContext` already provides this.
18. **Why thin controllers?** So HTTP concerns stay separate from business logic, keeping controllers simple, testable by inspection, and reusable across contexts.
19. **What is Infrastructure?** The layer containing technical implementation details — databases, external services, frameworks.
20. **Clean Architecture vs 3-tier?** 3-tier is a simpler, often less strict layered structure; Clean Architecture enforces an explicit inward dependency rule via interfaces.
21. **Clean Architecture vs Onion?** Nearly identical philosophies; Onion Architecture is considered a direct predecessor.
22. **Clean Architecture vs MVC?** MVC is a UI pattern that typically lives inside the Presentation layer of a Clean Architecture solution — not a competing whole-application architecture.
23. **How does testing benefit?** Business logic has no infrastructure dependency, so it can be unit tested quickly and reliably without a database or web server.
24. **What is overengineering?** Adding abstractions or layers that don't solve any real, current problem.
25. **How would you structure a large ASP.NET Core project?** Split into Domain, Application, Infrastructure, and API projects, following the dependency rule, with feature-based folders inside each.
26. **What is a Value Object?** An object defined by its values rather than an identity, typically immutable.
27. **What is a Domain Event?** A record of something significant that happened in the business, used to decouple side effects.
28. **Why avoid returning entities directly from an API?** To prevent leaking internal fields and to keep the API contract stable and independent of internal refactors.
29. **What's the difference between authentication and authorization?** Authentication verifies who you are; authorization verifies what you're allowed to do.
30. **Where do domain exceptions get handled?** Typically caught in centralized exception-handling middleware and translated into consistent HTTP error responses.

---

# 40. Viva / Quick Revision Questions

1. **What does "inward" mean in the Dependency Rule?** Toward the Domain, the business core.
2. **What layer has zero dependencies?** Domain.
3. **What owns repository interfaces?** Application (sometimes Domain).
4. **What owns repository implementations?** Infrastructure.
5. **What is a controller's only job?** Translate HTTP requests/responses; call a use case.
6. **What replaces business logic in a thin controller?** A Use Case.
7. **What enforces entity invariants?** Private setters plus factory/behavior methods.
8. **Give an example of a Value Object.** `EmailAddress`, `Money`.
9. **Give an example of an Entity.** `User`, `Post`.
10. **What distinguishes an Entity from a Value Object?** Identity vs. value equality.
11. **What is a Domain Event example?** `PostCreated`.
12. **What does DIP stand for?** Dependency Inversion Principle.
13. **What does SRP stand for?** Single Responsibility Principle.
14. **Name the SOLID principles.** SRP, OCP, LSP, ISP, DIP.
15. **What does OCP mean?** Open for extension, closed for modification.
16. **What does LSP mean?** Subtypes must be substitutable for their base types.
17. **What does ISP mean?** Don't force clients to depend on methods they don't use.
18. **Is Unit of Work mandatory in EF Core apps?** No — `DbContext` already provides it.
19. **What is CQRS in one sentence?** Separating read and write models/responsibilities.
20. **Is CQRS mandatory in Clean Architecture?** No.
21. **What does DTO stand for?** Data Transfer Object.
22. **Why not return entities from the API?** Security and API contract stability.
23. **What layer contains EF Core `DbContext`?** Infrastructure.
24. **What layer contains JWT token generation?** Infrastructure.
25. **What layer wires up `[Authorize]`?** Presentation/API.
26. **What is an anemic domain model?** Entities with no behavior, just properties — logic lives elsewhere.
27. **What causes an anemic domain model?** Overusing services for logic that should live on entities.
28. **What is a Fat Controller?** A controller doing validation, business logic, and persistence itself.
29. **What's the fix for a Fat Controller?** Delegate to Use Cases.
30. **What does the Repository Pattern hide?** How data is actually stored/retrieved.
31. **What's wrong with `IRepository<T>` everywhere?** It often leaks `IQueryable` and hides real use-case intent.
32. **Does EF Core's `DbSet<T>` already act like a repository?** Yes.
33. **What is MediatR?** A library implementing the mediator pattern for routing commands/queries to handlers.
34. **Is MediatR part of Clean Architecture?** No, it's an optional implementation choice.
35. **What is Onion Architecture's relationship to Clean Architecture?** Its direct predecessor; nearly identical.
36. **What is Vertical Slice Architecture?** Organizing code by feature instead of by technical layer.
37. **Can Clean Architecture and Vertical Slice coexist?** Yes — layer rules at the project level, feature folders within layers.
38. **Is Clean Architecture a deployment architecture?** No — it's an internal code organization approach.
39. **Can a monolith use Clean Architecture?** Yes.
40. **Can a microservice ignore Clean Architecture internally?** Yes, unfortunately — the two are independent concerns.
41. **What is the main benefit of Dependency Injection here?** It implements Dependency Inversion at runtime by wiring interfaces to implementations.
42. **What are the three common DI lifetimes in ASP.NET Core?** Transient, Scoped, Singleton.
43. **Which DI lifetime is `DbContext` typically registered as?** Scoped.
44. **What is a Domain Exception used for?** Signaling a business rule violation.
45. **What HTTP status code usually maps to a Domain Exception?** 400 Bad Request.

---

# 41. Common Interview Traps — "Things You Should NOT Say"

| Statement | Why it's wrong or incomplete |
|---|---|
| "Clean Architecture means four folders." | The folder structure is incidental; the *dependency rule* is what actually defines Clean Architecture — you could technically use different folder names and still follow (or violate) it. |
| "MediatR is required." | MediatR is one popular implementation choice for the Application layer, not a requirement of the architecture itself. |
| "Repository Pattern is mandatory." | It's the common way to satisfy Dependency Inversion for persistence, but not the only way — some teams abstract differently or minimally. |
| "Clean Architecture means microservices." | Clean Architecture is an internal code architecture; microservices is a deployment/distribution strategy. They're independent. |
| "Controllers should contain business logic." | This directly violates Separation of Concerns and makes logic untestable without HTTP infrastructure. |
| "Domain should use EF Core." | This breaks the Dependency Rule — Domain must stay framework-agnostic. |
| "More layers always mean better architecture." | Excess layering without a real need is overengineering, and can make a codebase harder to work with, not easier. |

---

# 42. Cheat Sheet

**Core Layers**
```
Domain
Application
Infrastructure
Presentation
```

**Dependency Direction**
```
Outer → Inner   (always)
```

**Responsibilities**
```
Domain          → Business rules
Application     → Use cases / orchestration
Infrastructure  → Technical implementations
API             → HTTP translation
```

**Golden Rules**
- Domain depends on nothing.
- Interfaces are owned by inner layers; implementations live in outer layers.
- Controllers stay thin — no business logic, no direct database access.
- Entities enforce their own invariants (private setters + behavior methods).
- DTOs, not entities, cross the API boundary.
- Repository interfaces belong to Application; implementations belong to Infrastructure.
- EF Core's `DbContext` already gives you Unit of Work — don't re-wrap it without a reason.
- CQRS, MediatR, and generic repositories are optional tools, not requirements.
- Add abstraction to solve a real problem — never "just in case."
- Clean Architecture is about code organization, not deployment topology.

---

# 43. Architecture Diagrams — Reference Set

**1. Overall Clean Architecture**
```
        Presentation
             ↓
        Application
             ↓
          Domain
             ↑
        Infrastructure
```

**2. Dependency direction**
```
Domain ← Application ← Infrastructure ← API
 (all arrows point INTO Domain)
```

**3. Request flow**
```
HTTP Request → Controller → Use Case → Domain → Repository Interface → Response
```

**4. Create Post flow**
```
Next.js → POST /api/posts → PostsController → CreatePostUseCase
        → Post.Create() → IPostRepository → PostRepository → EF Core → PostgreSQL
```

**5. Repository abstraction**
```
Application → IPostRepository ← PostRepository → EF Core → PostgreSQL
```

**6. Dependency Injection**
```
Program.cs (composition root)
   registers: IPostRepository → PostRepository
   registers: CreatePostUseCase
Controller asks for CreatePostUseCase → DI container supplies fully-wired instance
```

**7. Next.js + ASP.NET Core + PostgreSQL**
```
Next.js (Browser/Server) → HTTPS/JSON → ASP.NET Core API → EF Core → PostgreSQL
```

**8. Testing architecture**
```
Unit Tests        → Domain + Application (no infrastructure)
Integration Tests → API + Infrastructure + real/test PostgreSQL
E2E Tests          → Full stack, black-box
```

**9. Clean Architecture inside a microservice**
```
Post Service
 ├── Domain
 ├── Application
 ├── Infrastructure (its own DB)
 └── API
(Repeated independently for User Service, Notification Service, etc.)
```

---

# 44. Practical Exercises

## Beginner

**1. Create a Todo API using Clean Architecture.**
- Requirements: Add, complete, delete, and list todo items.
- Expected architecture: Domain (`TodoItem` entity), Application (`ITodoRepository`, use cases), Infrastructure (EF Core + PostgreSQL), API (controller).
- Folder structure: mirror Section 19, scaled down (no `Users`/feature subfolders needed yet).
- Practice: entity design with private setters, a repository interface, and a thin controller.

**2. Create a `User` entity.**
- Requirements: `Id`, `Username`, `PasswordHash`, a `Register` factory method enforcing a non-empty username.
- Practice: factory methods, encapsulation, domain exceptions.

**3. Create a repository abstraction.**
- Requirements: `IUserRepository` with `GetByIdAsync`, `AddAsync`.
- Practice: Dependency Inversion — define the interface in Application, implement in Infrastructure.

## Intermediate

**4. Add authentication.**
- Requirements: Register/Login endpoints, password hashing, JWT issuance.
- Expected architecture: `IPasswordHasher`, `ITokenGenerator` interfaces in Application; BCrypt/JWT implementations in Infrastructure.
- Practice: separating authentication (Infrastructure) from authorization (Presentation).

**5. Add comments.**
- Requirements: A `Comment` entity linked to a `Post`, with a max length rule.
- Practice: modeling a second entity and its relationship without letting EF Core concerns leak into Domain.

**6. Add likes.**
- Requirements: Enforce "a user cannot like the same post twice."
- Practice: business rule enforcement — decide whether this belongs on `Post`, `Like`, or a Domain Service.

**7. Add validation.**
- Requirements: Input validation via a validator class (e.g., FluentValidation-style) separate from business rules.
- Practice: distinguishing input validation from business validation (Section 25).

## Advanced

**8. Build the full Twitter Clone.**
- Requirements: All features listed in Section 21.1.
- Expected architecture: Full four-project solution with feature-based Application folders.

**9. Add notifications.**
- Requirements: Notify a user when their post is liked, using a Domain Event (`PostLiked`) handled asynchronously.
- Practice: decoupling side effects from the core operation.

**10. Add Redis caching.**
- Requirements: Cache `GetFeed` results.
- Practice: adding an `ICacheService` interface in Application, Redis implementation in Infrastructure — caching stays a swappable detail.

**11. Add background jobs.**
- Requirements: A scheduled job that recalculates trending posts.
- Practice: reusing Use Cases from a non-HTTP entry point (proving they're truly framework-agnostic).

**12. Add integration tests.**
- Requirements: Test `POST /api/posts` end-to-end against a real/test PostgreSQL instance.
- Practice: distinguishing what belongs in unit vs. integration tests (Section 27).

**13. Dockerize the application.**
- Requirements: Dockerfile for the API, docker-compose with PostgreSQL.
- Practice: seeing how Infrastructure choices (the database) are configuration, not code, at deployment time.

**14. Add CI/CD.**
- Requirements: A pipeline that runs unit tests, integration tests, and deploys on merge.
- Practice: seeing how fast, infrastructure-free unit tests (Section 27) make CI pipelines fast and reliable.

---

# 45. Final Mental Model

```
DOMAIN            → "What is the business?"
APPLICATION       → "What can the application do?"
INFRASTRUCTURE    → "How do we implement external dependencies?"
PRESENTATION      → "How does the outside world communicate with the application?"
```

- The business should not care about the database.
- The business should not care about HTTP.
- The business should not care about ASP.NET Core.
- The business should not care about PostgreSQL.

**External technologies depend on the business abstractions — never the other way around.** This single sentence, if truly internalized, is enough to correctly answer almost any Clean Architecture interview question, even ones you haven't seen phrased this way before.

---

# 46. Final Summary

## Clean Architecture in 10 Rules

1. Dependencies always point inward — never outward.
2. Domain has zero dependencies on frameworks, databases, or UI.
3. Business rules live in entities and domain services, not in controllers or repositories.
4. Interfaces are owned by inner layers; implementations live in outer layers.
5. Controllers stay thin — HTTP translation only.
6. DTOs cross boundaries; entities stay internal.
7. Use Cases represent one clear thing the system can do.
8. Testability is a *result* of correct dependency direction, not a separate effort.
9. CQRS, MediatR, and generic repositories are optional tools — use them only when they solve a real problem.
10. Match the amount of architecture to the size and lifespan of the project — avoid both a tangled mess and needless overengineering.

## Clean Architecture in 60 Seconds

Clean Architecture organizes an application into four layers — Domain, Application, Infrastructure, and Presentation — with one non-negotiable rule: dependencies only point inward, toward the business logic at the center. The Domain layer holds entities and business rules and depends on nothing. The Application layer defines use cases and the interfaces it needs (like repositories) without knowing how they're implemented. Infrastructure provides those implementations — EF Core, PostgreSQL, JWT, email — as replaceable technical details. Presentation (controllers) translates HTTP in and out, staying thin. The payoff: you can test business logic with zero infrastructure, swap technical details without touching business rules, and keep a growing codebase understandable. It's not about a fixed folder count or mandatory libraries like MediatR or CQRS — it's about protecting the business core from technical churn by consistently inverting dependencies through interfaces.

## Clean Architecture in One Diagram

```
+-------------------------------------------------------------+
|                       INFRASTRUCTURE                         |
|        (EF Core, PostgreSQL, JWT, Email, Redis, APIs)        |
|   +-------------------------------------------------------+  |
|   |                     PRESENTATION                        |  |
|   |                (Controllers, HTTP)                      |  |
|   |   +---------------------------------------------+      |  |
|   |   |                  APPLICATION                  |      |  |
|   |   |          (Use Cases, DTOs, Interfaces)         |      |  |
|   |   |   +---------------------------------------+   |      |  |
|   |   |   |                 DOMAIN                  |   |      |  |
|   |   |   |      (Entities, Rules, Events)           |   |      |  |
|   |   |   +---------------------------------------+   |      |  |
|   |   +---------------------------------------------+      |  |
|   +-------------------------------------------------------+  |
+-------------------------------------------------------------+

              All arrows of dependency point INWARD →
        Nothing at the center knows anything outside itself.
```

---

*End of book. Revisit Section 42 (Cheat Sheet) the night before an interview, and Sections 39–41 (Interview Questions, Viva Questions, and Common Traps) for a final pass.*
