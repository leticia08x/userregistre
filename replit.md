# Overview

This project is a **User Registration System** designed as a progressive educational exercise in programming logic. The system is built to teach fundamental programming concepts through incremental development stages, starting from basic input/output operations and evolving toward a complete user management system.

The final system should support:
- User registration (name and age)
- Listing all registered users
- Searching for specific users by name
- Program termination/exit functionality

The project emphasizes hands-on practice with core programming concepts including variables, input/output, conditional logic, loops, arrays/lists, and functions.

# User Preferences

Preferred communication style: Simple, everyday language.
Language preference: Portuguese (Brazil)

# System Architecture

## Application Structure
The system implements all stages in a **complete integrated solution** built in C language:

**Implemented Features:**
- User data collection (name and age) with personalized welcome messages
- Menu-driven interface with switch/case statements and while loop
- Multiple user registration using struct array (up to 5 users maximum)
- List all registered users with formatted output
- Case-insensitive name search functionality
- Input validation and buffer management to prevent overflow
- Graceful program termination

## Design Patterns
**Educational Incremental Design**: Each stage builds upon the previous, allowing learners to understand how simple programs evolve into complex systems.

**Interactive Console-Based Interface**: The system uses command-line interaction patterns with `scanf()` and `fgets()` for data collection and `printf()` for formatted output display.

## Data Management Approach
**In-Memory Storage**: The system uses C arrays to store user records during program execution.

**Data Structure**: User records are stored using a `struct Usuario` containing:
- `char nome[100]` - User's name (up to 100 characters)
- `int idade` - User's age

The system maintains an array of up to 5 Usuario structs and tracks the total count.

## Core Functionalities
1. **User Registration** - Collect and store user information
2. **List Users** - Display all registered users
3. **Search Functionality** - Find users by name
4. **Menu System** - Provide navigation between different operations
5. **Exit Mechanism** - Graceful program termination

# External Dependencies

This appears to be a **pure educational programming exercise** with minimal external dependencies:

**Language**: C (implemented with standard C libraries)

**Standard Library Only**: The project uses only C's standard libraries:
- `stdio.h` - Input/output operations (printf, scanf, fgets)
- `string.h` - String manipulation (strcspn)
- `strings.h` - Case-insensitive string comparison (strcasecmp)
- `stdlib.h` - General utilities

**Compiler**: Clang (C compiler toolchain installed)

**No External Integrations**: This is a standalone console application without:
- Database connections
- Web frameworks
- Third-party APIs
- External file systems (currently in-memory only)

**Note**: Future enhancements might introduce file persistence using C's file I/O functions, but this is not present in the current implementation.