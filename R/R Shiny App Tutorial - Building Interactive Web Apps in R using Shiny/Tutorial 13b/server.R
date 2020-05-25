library(shiny)

shinyServer(function(input, output) {
  output$tabs <- renderUI({
    # According to tutorial 08
    # Structure for tabs:
    # tabsetpanel(type = "tab",
    #             tabPanel("Summary", verbatimTextOutput("my_summary")),
    #             tabPanel("Structure", verbatimTextOutput("str")),
    #             tabPanel("Data", tableOutput("data")),
    #             tabPanel("Plot", plotOutput("my_hist")))
    #
    # paste: create arguments for tabPanel
    # lapply: pass the result from paste to tabPanel function
    # do.call: pass Tabs to tabsetPanel function
    Tabs <- lapply(paste("tab no.", 1:input$n), tabPanel)
    do.call(tabsetPanel, Tabs)
  })
})
